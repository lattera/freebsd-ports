# New ports collection makefile for:	cmake-gui
# Date created:		2009-08-27
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cmake
PORTVERSION=	2.8.9
CATEGORIES=	devel
MASTER_SITES=	http://www.${PORTNAME}.org/files/v${PORTVERSION:C/\.[[:digit:]]+$//}/
PKGNAMESUFFIX=	-gui

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 GUI for cmake

RUN_DEPENDS=	${CMAKE_BIN}:${CMAKE_PORT}

USE_QT4=	gui qmake_build moc_build uic_build rcc_build
USE_CMAKE=	yes
CMAKE_ARGS=	-DBUILD_QtDialog:bool=on \
		-DCMAKE_DATA_DIR:STRING="/${DATADIR_REL}" \
		-DCMAKE_DOC_DIR:STRING="/${DOCSDIR_REL}"
MAN1=		cmake-gui.1

BUILD_WRKSRC=	${WRKSRC}/Source/QtDialog
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
			s,/usr/X11R6,${LOCALBASE},g'

pre-install:
	${LN} -sf ${CMAKE_BIN} ${WRKSRC}/bin
	${WRKSRC}/bin/cmake-gui --help-man > ${WRKSRC}/cmake-gui.1

post-install:
	${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cmake-gui.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
