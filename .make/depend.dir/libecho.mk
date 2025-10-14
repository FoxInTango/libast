DEPEND_TARGETS += libecho.recursive
ECHO_TARGETS += libecho.echo
libecho.recursive:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libecho/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libecho/.make/super
	cd /Users/lidali/alpine/libraries/libecho/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make recursive && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
	-rm /Users/lidali/alpine/libraries/libecho/.make/super
libecho.echo:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libast/               >> /Users/lidali/alpine/libraries/libecho/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libast/.make >> /Users/lidali/alpine/libraries/libecho/.make/super
	cd /Users/lidali/alpine/libraries/libecho/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make echo
	-rm /Users/lidali/alpine/libraries/libecho/.make/super
