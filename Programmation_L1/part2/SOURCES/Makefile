all : slide03 slide14 slide17 slide18 slide21 slide26 slide27 slide28 slide35 \
      slide38

slide03 : slide03.c
	gcc slide03.c -o slide03

slide14 : slide14.c
	gcc slide14.c -o slide14

slide17 : slide17.c
	gcc slide17.c -o slide17

slide18 : slide18.cpp
	g++ slide18.cpp -o slide18

slide21 : slide21.c
	gcc $< -o $@

slide26 : slide26.cpp
	g++ $< -o $@

slide27 : slide27.cpp
	g++ $< -o $@

slide28 : slide28.cpp
	g++ $< -o $@

slide35 : slide35.cpp
	g++ $< -o $@

slide38 : slide38.cpp
	g++ $< -o $@

clean :
	rm -f slide03 slide14 slide17 slide18 slide21 slide26 slide27 \
          slide28 slide35 slide38


