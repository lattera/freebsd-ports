# New ports collection makefile for:	transmission-gtk2
# Date created:				11 February 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-gtk2

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A fast and lightweight GTK+2 BitTorrent client

BROKEN=		Relies on GTK 3.0 version > 3.2.0; use net-p2p/transmission25-gtk20

LIB_DEPENDS=	${GEN_LIB_DEPENDS} \
		notify.4:${PORTSDIR}/devel/libnotify \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${GEN_RUN_DEPENDS} \
		xdg-open:${PORTSDIR}/devel/xdg-utils

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission-cli
PLIST=		${.CURDIR}/pkg-plist
SLAVEPORT=	gtk2

USE_GNOME=	gnomehack gtk20 desktopfileutils intlhack
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

EXTRA_CONF_ARGS=--disable-cli \
		--disable-daemon \
		--with-gtk \
		--enable-inotify \
		--disable-mac \
		--enable-nls

MAN1=		transmission-gtk.1

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|TryExec=.*||g ; /^$$/d' \
		${WRKSRC}/gtk/transmission-gtk.desktop.in

post-install: general-install
	@-update-desktop-database

.include "${MASTERDIR}/Makefile"
