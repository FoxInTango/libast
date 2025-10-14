DEPEND_TARGETS += libmodule.recursive
ECHO_TARGETS += libmodule.echo
libmodule.recursive:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libmodule/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libmodule/.make/super
	cd /Users/lidali/alpine/libraries/libmodule/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make recursive && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
	-rm /Users/lidali/alpine/libraries/libmodule/.make/super
libmodule.echo:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libmodule/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libmodule/.make/super
	cd /Users/lidali/alpine/libraries/libmodule/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make echo
	-rm /Users/lidali/alpine/libraries/libmodule/.make/super
