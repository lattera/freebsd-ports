# New ports collection makefile for:	mucommander
# Date created:		2007-06-24
# Whom:			Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	mucommander
PORTVERSION=	0.8.5
CATEGORIES=	x11-fm java
MASTER_SITES=	http://www.mucommander.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Lightweight file manager featuring a Norton Commander style interface

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

PLIST_FILES=	bin/mucommander %%DATADIR%%/mucommander.jar %%DATADIR%%/license.txt
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	mucommander

PORTDOCS=	readme.txt

WRKSRC=		${WRKDIR}/muCommander-${PORTVERSION:S/./_/g}

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mucommander.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mucommander ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
