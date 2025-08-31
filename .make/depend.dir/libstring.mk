DEPEND_TARGETS += libstring.build
ECHO_TARGETS += libstring.echo
libstring.build:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libast/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libstring/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libast/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libstring/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libstring/ && make && make install
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libstring/.make/super
libstring.echo:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libast/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libstring/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libast/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libstring/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libstring/ && make echo
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libstring/.make/super
