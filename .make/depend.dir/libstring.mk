DEPEND_TARGETS += libstring.recursive
ECHO_TARGETS += libstring.echo
libstring.recursive:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libstring/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libstring/.make/super
	cd /Users/lidali/alpine/libraries/libstring/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make recursive && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
	-rm /Users/lidali/alpine/libraries/libstring/.make/super
libstring.echo:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libstring/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libstring/.make/super
	cd /Users/lidali/alpine/libraries/libstring/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make echo
	-rm /Users/lidali/alpine/libraries/libstring/.make/super
