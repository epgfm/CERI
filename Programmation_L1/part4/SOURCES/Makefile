all : slide06 slide07 slide08 slide09 slide10 slide11 slide20/main \
      slide23/main slide24 slide25 slide26



slide06 : slide06.cpp
	g++ $< -o $@

slide07 : slide07.cpp
	g++ $< -o $@

slide08 : slide08.cpp
	g++ $< -o $@

slide09 : slide09.cpp
	g++ $< -o $@

slide10 : slide10.cpp
	g++ $< -o $@

slide11 : slide11.cpp
	g++ $< -o $@

slide20/main :
	$(MAKE) -C slide20/

slide23/main :
	$(MAKE) -C slide23/

slide24 : slide24.cpp
	g++ $< -o $@

slide25 : slide25.cpp
	g++ $< -o $@

slide26 : slide26.cpp
	g++ $< -o $@



clean :
	rm -f slide06 slide07 slide08 slide09 slide10 slide11
	$(MAKE) -C slide20/ clean
	$(MAKE) -C slide23/ clean
	rm -f slide24 slide25 slide26 *~



