DEPEND_TARGETS += libmodule.recursive
ECHO_TARGETS += libmodule.echo
libmodule.recursive:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libast/               >> /home/lidali/alpine/libraries/libmodule/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libast/.make >> /home/lidali/alpine/libraries/libmodule/.make/super
	cd /home/lidali/alpine/libraries/libmodule/ && make recursive && make install
	-rm /home/lidali/alpine/libraries/libmodule/.make/super
libmodule.echo:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libast/               >> /home/lidali/alpine/libraries/libmodule/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libast/.make >> /home/lidali/alpine/libraries/libmodule/.make/super
	cd /home/lidali/alpine/libraries/libmodule/ && make echo
	-rm /home/lidali/alpine/libraries/libmodule/.make/super
