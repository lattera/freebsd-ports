# Created by: ijliao
# $FreeBSD$

PORTNAME=	smb
PORTVERSION=	1.1.2
CATEGORIES=	net python
MASTER_SITES=	http://miketeo.net/files/Projects/py${PORTNAME}/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysmb-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	SMB/CIFS library written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	py${PORTNAME}

DOCSDIR=	${PREFIX}/share/doc/py-smb

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _modules/ ${DOCSDIR}/)
	@(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _static/ ${DOCSDIR}/)
	@(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} api/ ${DOCSDIR}/)
	@(cd ${WRKSRC}/docs/html/ && ${CP} *.html ${DOCSDIR}/)
	@(cd ${WRKSRC}/docs/html/ && ${CP} *.js ${DOCSDIR}/)
.endif

.include <bsd.port.mk>
