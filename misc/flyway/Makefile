# ex:ts=8
# Ports collection makefile for:	flyway
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flyway
PORTVERSION=	0.4.1
PORTREVISION=	8
CATEGORIES=	misc python geography
MASTER_SITES=	http://www.bellz.org/flyway/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A VFR/IFR Route Planner for Pilots

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_PYTHON=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/FlyWay
PORTDOCS=	README.html INSTALL LICENSE

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|doc||' \
		${WRKSRC}/install.py
.endif

do-install:
	(cd ${WRKSRC};${PYTHON_CMD} ${WRKSRC}/install.py -p ${PREFIX})

.include <bsd.port.mk>
