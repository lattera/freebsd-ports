# New ports collection makefile for:	megaglest
# Date created:				2011-02-10
# Whom:					Sven Moeller <smoeller@nichthelfer.de>
#
# $FreeBSD$
#

PORTNAME=	megaglest
PORTVERSION=	3.6.0.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_${PORTVERSION}/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Open source 3D real-time strategy game

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2 \
		ftgl.2:${PORTSDIR}/graphics/ftgl \
		vorbis.4:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	${LOCALBASE}/include/libircclient.h:${PORTSDIR}/irc/libircclient \
		${LOCALBASE}/include/miniupnpc/miniupnpc.h:${PORTSDIR}/net/miniupnpc
RUN_DEPENDS=	${DATADIR}/tutorials/2_basic_tutorial/2_basic_tutorial.xml:${PORTSDIR}/games/megaglest-data

SUB_FILES=	pkg-message

USE_XZ=		yes
USE_CMAKE=	yes
USE_DOS2UNIX=	yes
USE_GL=		glew gl glu
USE_LUA=	5.1
USE_OPENAL=	al alut
USE_SDL=	yes
USE_WX=		2.8+
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include/libpng15
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS=	EDITOR "Install MegaGlest Editor" off

.include <bsd.port.options.mk>

.if defined(WITH_EDITOR)
PLIST_SUB+=	EDITOR=""
.else
PLIST_SUB+=	EDITOR="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' \
		${WRKSRC}/source/shared_lib/sources/platform/posix/miniftpclient.cpp

do-install:
	${STRIP_CMD} ${WRKSRC}/mk/linux/megaglest
	@${MKDIR} ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/mk/linux/megaglest ${PREFIX}/bin/${PORTNAME}
.for f in glest.ini glestkeys.ini servers.ini
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.for f in AUTHORS.source_code.txt CHANGELOG.txt README.txt COPYRIGHT.source_code.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.if defined(WITH_EDITOR)
	${INSTALL_PROGRAM} ${WRKSRC}/mk/linux/megaglest_editor ${PREFIX}/bin/megaglest_editor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: unrecognized compiler flags
.endif

.include <bsd.port.post.mk>
