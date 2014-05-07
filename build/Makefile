# This Penguin project main Makefile

# include colored output functions
include $(CURRENT_MAKEFILE_PATH)Print.am

all: libcore libprotocol libtransport

libcore:
	$(call i_print, Building libcore)

libprotocol:
	$(call e_print, Building libprotocol)

libtransport:
	$(call w_print, Building libtransport)

penguin:
	gcc -o penguin ../source/PfMain.c ../source/libcore/PfDebug.c ../source/libcore/PfTime.c -I../include -I../include/libcore

clean:
	rm -rf ../. *.o penguin
	