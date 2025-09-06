DEPEND_TARGETS += libstream.recursive
ECHO_TARGETS += libstream.echo
libstream.recursive:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libast/               >> /home/lidali/alpine/libraries/libstream/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libast/.make >> /home/lidali/alpine/libraries/libstream/.make/super
	cd /home/lidali/alpine/libraries/libstream/ && make recursive && make install
	-rm /home/lidali/alpine/libraries/libstream/.make/super
libstream.echo:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libast/               >> /home/lidali/alpine/libraries/libstream/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libast/.make >> /home/lidali/alpine/libraries/libstream/.make/super
	cd /home/lidali/alpine/libraries/libstream/ && make echo
	-rm /home/lidali/alpine/libraries/libstream/.make/super
