# New ports collection makefile for:	gwrite
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gwrite
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	editors python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple HTML format editor

LICENSE=	LGPL3 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distutils-extra>=2.15:${PORTSDIR}/devel/py-distutils-extra \
		intltool-update:${PORTSDIR}/textproc/intltool \
		${PYTHON_PKGNAMEPREFIX}jswebkit>=0:${PORTSDIR}/www/py-jswebkit \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:${PORTSDIR}/www/py-webkitgtk
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		wvHtml:${PORTSDIR}/textproc/wv \
		${PYTHON_PKGNAMEPREFIX}jswebkit>=0:${PORTSDIR}/www/py-jswebkit \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:${PORTSDIR}/www/py-webkitgtk

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
