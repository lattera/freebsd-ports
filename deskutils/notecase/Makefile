# New ports collection makefile for:	notecase
# Date created:				19 July 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	notecase
PORTVERSION=	1.9.8
PORTREVISION=	7
CATEGORIES=	deskutils textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A hierarchical text notes manager

LICENSE=	BSD

USE_GMAKE=	yes
USE_GNOME=	gtk20 gtksourceview2 gnomevfs2 desktopfileutils pkgconfig
USE_GETTEXT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	help.ncd
INSTALL_TARGET=	install docinstall
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^prefix=.*|prefix=${PREFIX}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^docsdir=.*|docsdir=${DOCSDIR}|' \
		${WRKSRC}/Makefile

post-install:
	@-update-mime-database ${PREFIX}/share/mime
	@-update-desktop-database

.include <bsd.port.mk>
