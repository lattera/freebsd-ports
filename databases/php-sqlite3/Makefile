# New ports collection makefile for:	php-sqlite3
# Date created:			26 Sep 2006
# Whom:				Simon Cornelius P. Umacob <simoncpu@infoweapons.com>
#
# $FreeBSD$
#

PORTNAME=		sqlite3
PORTVERSION=		0.5
CATEGORIES=		databases
MASTER_SITES=		SF/php-${PORTNAME}/source%20code/release%20${PORTVERSION}
PKGNAMEPREFIX=		php-
EXTRACT_SUFX=		.tgz

MAINTAINER=		glarkin@FreeBSD.org
COMMENT=		A port for the PHP sqlite3 extension

BUILD_DEPENDS=		sqlite3>=3.0:${PORTSDIR}/databases/sqlite3

DEPRECATED=		No upstream development and superseded by databases/php5-sqlite3 and databases/php53-sqlite3
EXPIRATION_DATE=	2012-06-21

CONFIGURE_ARGS=		--with-sqlite3=${LOCALBASE}
USE_PHP=		yes
USE_PHPIZE=		yes
USE_PHPEXT=		yes
USE_PHP_BUILD=		yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

.include <bsd.port.mk>
