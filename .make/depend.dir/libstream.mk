DEPEND_TARGETS += libstream.recursive
ECHO_TARGETS += libstream.echo
libstream.recursive:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libstream/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libstream/.make/super
	cd /Users/lidali/alpine/libraries/libstream/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make recursive && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
	-rm /Users/lidali/alpine/libraries/libstream/.make/super
libstream.echo:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libstream/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libstream/.make/super
	cd /Users/lidali/alpine/libraries/libstream/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make echo
	-rm /Users/lidali/alpine/libraries/libstream/.make/super
