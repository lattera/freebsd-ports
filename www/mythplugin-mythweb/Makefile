# New ports collection makefile for:	mythplugin-mythweb
# Date created:		2009-12-27
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	mythweb
PORTVERSION=	0.25.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.osuosl.org/pub/mythtv/old_releases/ \
		http://ftp.oregonstate.edu/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/old_releases/
PKGNAMEPREFIX=	mythplugin-
DISTNAME=	mythplugins-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A frontend for scheduling and managing recordings on your MythTV Box

RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PHP=	spl session mysql pcre posix json
SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ""

OPTIONS=	APACHE "Enable Apache Support" on \
		LIGHTTPD "Enable Lighttpd Support" off

.include <bsd.port.options.mk>

.if defined(WITH_APACHE)
USE_APACHE_RUN=	22+
.endif

.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/var/www/html|${WWWDIR}|' \
		${WRKSRC}/mythweb/mythweb.conf.apache
	@${REINPLACE_CMD} -e 's|/usr/bin/php-cgi|${LOCALBASE}/bin/php-cgi|' \
		${WRKSRC}/mythweb/mythweb.conf.lighttpd

do-install:
	${MKDIR} ${WWWDIR}
	${MKDIR} ${WWWDIR}/data
	(cd ${WRKSRC}/mythweb/ && ${COPYTREE_SHARE} "*" ${WWWDIR} "! -name *.orig")

	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} -R 775 ${WWWDIR}/data

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
