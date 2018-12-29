
SRC_URI_remove = "file://HiPlayer.patch \
	file://HiPlayer-Subs.patch  \
	file://kodi-platform-support.patch \
	file://EGLNativeTypeMali.patch \
"
SRCDATE = "20180928"

SRC_URI_append = " http://source.mynonpublic.com/octagon/hiplayer_${SRCDATE}.tar.gz \
	file://stb-platform.patch \
	file://hiplayer-octagon.patch \
"

SRC_URI[md5sum] = "c3023661e9ff5df350b84e0bf3fef2d7"
SRC_URI[sha256sum] = "e2fdfa6b2e6b92aa10326833d27c4587efb47c614e53e14549ea5702bd403b58"
DEPENDS += "octagon-libs-${MACHINE}"
PROVIDES += "virtual/kodi"
RPROVIDES_${PN} += "virtual/kodi"
PROVIDES += "kodi"
RPROVIDES_${PN} += "kodi"

RDEPENDS_${PN} += "octagon-libs-${MACHINE}"
RDEPENDS_${PN} += "octagon-opengl-${MACHINE}"

EXTRA_OECONF += " \
    --with-platform=clap-cortexa15 \
    --with-ffmpeg=stb \
"
do_configure_prepend() {
    install -d ${WORKDIR}/git/xbmc/linux/hisi
    install -d ${WORKDIR}/git/xbmc/cores/hiplayer
    install -m 0755 ${WORKDIR}/hiadp.a ${WORKDIR}/git/xbmc/linux/hisi/
    install -m 0755 ${WORKDIR}/hiplayer.a ${WORKDIR}/git/xbmc/cores/hiplayer/
}

