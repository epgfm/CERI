#! /usr/bin/tclsh

package require Tk

wm title . "Reversi"

#----------------------------------------------------------------------------#
#                         Creation of GUI components.                        #
#----------------------------------------------------------------------------#
image create photo empty -file "res/empty.gif"
image create photo black -file "res/black.gif"
image create photo white -file "res/white.gif"
image create photo line  -file "res/line.gif"

for {set i 1} {$i < 9} {incr i} { image create photo $i -file "res/$i.gif" }

#----------------------------------------------------------------------------#
#                             Initial GUI build.                             #
#----------------------------------------------------------------------------#
grid [frame .board] -sticky nswe
grid columnconfigure . 0 -weight 1 ; grid rowconfigure . 0 -weight 1

# Image: A-H labels at the top of the board.
grid [label .top] -column 0 -row 0 -columnspan 10 -sticky nswe
.top configure -image line -bd 0

for {set r 0} {$r < 8} {incr r} {

    # 1-8 labels on the left of the grid.
    grid [label .l$r] -row [expr $r+1] -column 0 -sticky nswe
    .l$r configure -image [expr $r+1] -bd 0

    # [A1 -> H8] Cells.
    for {set c 0} {$c < 8} {incr c} {
        grid [label .$r$c] -row [expr $r+1] -column [expr $c+1] -sticky nswe
        .$r$c configure -image empty -bd 0
        set command [format %c [expr $c+0x41]][format %c [expr $r+1+0x30]]
        bind .$r$c <1> "gui-->exe $command"
    }

    # 1-8 labels on the right of the grid.
    grid [label .r$r] -row [expr $r+1] -column 9 -sticky nswe
    .r$r configure -image [expr $r+1] -bd 0

}

# Image: A-H labels at the bottom of the board.
grid [label .down] -column 0 -row 9 -columnspan 10 -sticky nswe
.down configure -image line -bd 0

grid [label .pass] -column 0 -row 10 -columnspan 10 -sticky nswe
.pass configure -text "PASS"
bind .pass <1> "gui-->exe PASS"

#----------------------------------------------------------------------------#
#               Processes linking the GUI and the executable                 #
#----------------------------------------------------------------------------#
proc gui-->exe {msg} {
    upvar 1 execPipe execPipe
    puts $execPipe "$msg"
    puts "$msg"
    flush $execPipe
}

proc gui<--exe {execPipe} {
    if {![eof $execPipe]} {
        set line [split [gets $execPipe]]
        puts $line

        if {[llength $line] == 11 && [lindex $line 0] == "BOARD"} {
            set row [lindex $line 1]
            set col 0
            global .
            foreach cell [lrange $line 2 end-1] {
                switch -exact -- $cell {
                    E { .$row$col configure -image empty }
                    X { .$row$col configure -image white }
                    O { .$row$col configure -image black }
                }
                incr col
            }
        }
    } else { close $execPipe }
}

#----------------------------------------------------------------------------#
#                          Program Launch Sequence                           #
#----------------------------------------------------------------------------#
set execPipe [open "|./main raw" "r+"]
fconfigure $execPipe -blocking 0
gui-->exe "B\nH" ; # Send the init sequence to the program.
fileevent $execPipe readable "gui<--exe $execPipe"


