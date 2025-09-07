DEPEND_TARGETS += libstring.recursive
ECHO_TARGETS += libstring.echo
libstring.recursive:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libast/               >> /home/lidali/alpine/libraries/libstring/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libast/.make >> /home/lidali/alpine/libraries/libstring/.make/super
	cd /home/lidali/alpine/libraries/libstring/ && make recursive && make install
	-rm /home/lidali/alpine/libraries/libstring/.make/super
libstring.echo:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libast/               >> /home/lidali/alpine/libraries/libstring/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libast/.make >> /home/lidali/alpine/libraries/libstring/.make/super
	cd /home/lidali/alpine/libraries/libstring/ && make echo
	-rm /home/lidali/alpine/libraries/libstring/.make/super
