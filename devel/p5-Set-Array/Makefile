# New ports collection makefile for:	devel/p5-Set-Array
# Date created:				2 September 2004
# Whom:					Alex Kapranoff <kappa@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	Set-Array
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Arrays as objects with set operations

LICENSE=	ART10

BUILD_DEPENDS=	p5-Try-Tiny>=0.11:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-Want>=0:${PORTSDIR}/devel/p5-Want
RUN_DEPENDS=	p5-Try-Tiny>=0.11:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-Want>=0:${PORTSDIR}/devel/p5-Want

TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod

PERL_MODBUILD=	yes

MAN3=		Set::Array.3

.include <bsd.port.mk>
