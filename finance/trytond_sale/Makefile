# New ports collection makefile for:	trytond_sale
# Date created:		08 September, 2012
# Whom:			Matthias Petermann<matthias@petermann.it>
#
# $FreeBSD$
#

PORTNAME=	trytond_sale
PORTVERSION=	2.4.0
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Sale Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_account_invoice>=2.4.1:${PORTSDIR}/finance/trytond_account_invoice \
		trytond_stock>=2.4.0:${PORTSDIR}/finance/trytond_stock

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
