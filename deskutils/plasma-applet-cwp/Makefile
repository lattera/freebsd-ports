# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	cwp
PORTVERSION=	1.6.4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	98925-cwp-${PORTVERSION}

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	Weather plasma applet for KDE4

LICENSE=	GPLv3

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT4=	gui dbus network opengl svg phonon webkit xml \
		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
