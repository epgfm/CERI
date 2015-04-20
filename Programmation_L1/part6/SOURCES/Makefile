all : slide16/main slide20/main slide24

slide16/main :
	$(MAKE) -C slide16/

slide20/main :
	$(MAKE) -C slide20/

slide24 : slide24.cpp
	g++ $< -o $@

clean :
	$(MAKE) -C slide16/ clean
	$(MAKE) -C slide20/ clean
	rm -f slide24 *~
