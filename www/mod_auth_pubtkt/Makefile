# Created by: Manuel Kasper <mk@neon1.net>
# $FreeBSD$

PORTNAME=	mod_auth_pubtkt
PORTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	https://neon1.net/mod_auth_pubtkt/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	mk@neon1.net
COMMENT=	An Apache module to provide public key ticket based authentication

MAKE_JOBS_SAFE=	yes

USE_APACHE=	22+
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--apxs=${APXS}

.include <bsd.port.mk>
