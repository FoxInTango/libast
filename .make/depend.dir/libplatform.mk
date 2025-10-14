DEPEND_TARGETS += libplatform.recursive
ECHO_TARGETS += libplatform.echo
libplatform.recursive:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libplatform/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libplatform/.make/super
	cd /Users/lidali/alpine/libraries/libplatform/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make recursive && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
	-rm /Users/lidali/alpine/libraries/libplatform/.make/super
libplatform.echo:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libplatform/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libplatform/.make/super
	cd /Users/lidali/alpine/libraries/libplatform/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make echo
	-rm /Users/lidali/alpine/libraries/libplatform/.make/super
