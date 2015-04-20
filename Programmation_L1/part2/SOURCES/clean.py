#! /usr/bin/env python

import sys
import re

#-----------------------------------------------------------------------------#
#     Clean the row numbers from the code samples copied from the slides.     #
#                    (First 3 characters of each line...)                     #
#-----------------------------------------------------------------------------#

if len(sys.argv) != 2:
    sys.exit(1)

file = open(sys.argv[1])

for line in file:
    line = re.sub("^...", "", line)
    print line.strip("\n")

file.close()
