# New ports collection makefile for:	uhidd
# Date created:		2009-08-07
# Whom:			Kai Wang <kaiwang27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uhidd
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE \
		http://people.freebsd.org/~kaiw/distfiles/

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	Userland USB HID device driver using libusb20

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS=	DEVD "Install devd files" on

MAKE_ENV+=	SYSDIR=${SYSDIR}
KMODDIR?=	/boot/modules
SRC_BASE?=	/usr/src
SYSDIR?=	${SRC_BASE}/sys

USE_RC_SUBR=	uhidd
SUB_FILES=	pkg-message
PLIST_SUB=	KMODDIR=${KMODDIR}

MAN4=		uvhid.4
MAN5=		uhidd.conf.5
MAN8=		uhidd.8

.include <bsd.port.pre.mk>

.if defined(DEBUG_FLAGS)
MAKE_ENV+=	DEBUG_FLAGS='${DEBUG_FLAGS}'
.endif

.if ${OSVERSION} < 800069
IGNORE=		does not build with the old USB stack
.elif ${OSVERSION} > 1000012
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-uhidd-parser.y
.endif

.if !(exists(${SYSDIR}/Makefile) || exists(${SRC_BASE}/sys/Makefile))
IGNORE=		requires kernel source files
.endif

.if !defined(WITHOUT_DEVD)
PLIST_SUB+=	PL_DEVD=""
.else
PLIST_SUB+=	PL_DEVD="@comment "
.endif

post-patch:	.SILENT
	${FIND} ${WRKSRC}/uhidd -type f -exec ${REINPLACE_CMD} \
		's|/usr/local|${PREFIX}|g' {} +
	${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/uhidd/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhidd/uhidd ${PREFIX}/sbin/uhidd
	${INSTALL_KLD} ${WRKSRC}/uvhid/uvhid.ko ${KMODDIR}/uvhid.ko
.if exists(${WRKSRC}/uvhid/uvhid.ko.symbols)
	${INSTALL_KLD} ${WRKSRC}/uvhid/uvhid.ko.symbols ${KMODDIR}/uvhid.ko.symbols
.endif
	${INSTALL_MAN} ${WRKSRC}/uhidd/uhidd.8 ${PREFIX}/man/man8/uhidd.8
	${INSTALL_MAN} ${WRKSRC}/uhidd/uhidd.conf.5 ${PREFIX}/man/man5/uhidd.conf.5
	${INSTALL_MAN} ${WRKSRC}/uvhid/uvhid.4 ${PREFIX}/man/man4/uvhid.4
.if !defined(WITHOUT_DEVD)
	${MKDIR} ${PREFIX}/etc/devd
	${REINPLACE_CMD} -Ee \
		"s%/usr/local%${PREFIX}%" ${WRKSRC}/uhidd/uhidd-devd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/uhidd/uhidd-devd.conf.sample ${PREFIX}/etc/devd/
	@if [ ! -f ${PREFIX}/etc/devd/uhidd-devd.conf ]; then \
		${CP} -p ${PREFIX}/etc/devd/uhidd-devd.conf.sample \
			${PREFIX}/etc/devd/uhidd-devd.conf; \
	fi
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
