# New ports collection makefile for:	nagios-check_nick
# Date created:				2009-07-11
# Whom:					steinex
#
# $FreeBSD$

PORTNAME=	check_nick
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nognu.de/s/FreeBSD/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plug-in to check if a nick is on IRC

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/irclib.py:${PORTSDIR}/irc/py-irclib

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_nick ${PREFIX}/libexec/nagios

.include <bsd.port.mk>
