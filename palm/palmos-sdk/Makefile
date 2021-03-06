# New ports collection makefile for:	Palm OS SDK
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palmos-sdk
PORTVERSION=	${SDKVER}r3
CATEGORIES=	palm
MASTER_SITES=
DISTFILES=	palmos-sdk-${SDKVER}r3-1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Palm OS SDK

RESTRICTED=	License agreement is required.
WRKSRC=		${WRKDIR}/sdk-5r3
NO_BUILD=	YES
PLIST_SUB=	BASEDIR=palmdev/sdk-${SDKVER}

SDKVER=		5.1.0
INCDIR=		${PREFIX}/palmdev/sdk-${SDKVER}/include
LIBDIR=		${PREFIX}/palmdev/sdk-${SDKVER}/lib

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE='The distribution file for this port may not be automatically fetched due to licensing restrictions.'
.endif

do-fetch:
.if !exists(${DISTDIR}/palmos-sdk-${SDKVER}r3-1.tar.gz)
	@${ECHO} ""
	@${ECHO} "You must manually fetch the palmos-sdk tarfile from:"
	@${ECHO} ""
	@${ECHO} "http://www.accessdevnet.com/index.php/Garnet-OS-SDK-68K-R3-PRC-tools-Generic-UNIX/View-category.html"
	@${ECHO} ""
	@${ECHO} "You will be required to register on the site."
	@${ECHO} ""
	@${ECHO} "After fetching the file, move it to
	@${ECHO} "${DISTDIR}/palmos-sdk-${SDKVER}r3-1.tar.gz"
	@${ECHO} "and run make again."
	@${FALSE}
.endif

do-install:
	${MKDIR} ${INCDIR} ${LIBDIR}
	${CP} -Rp ${WRKSRC}/include/* ${INCDIR}
	${CP} -Rp ${WRKSRC}/lib/* ${LIBDIR}
	${CP} -p "${WRKSRC}/Palm License.txt" "${WRKSRC}/PalmOS 5 SDK 68K R3 Readme.txt" ${PREFIX}/palmdev/sdk-${SDKVER}/
	${CHOWN} -R root:wheel ${INCDIR} ${LIBDIR}

.include <bsd.port.post.mk>
