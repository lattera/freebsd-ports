# New ports collection makefile for:	ExtUtils-MakeMaker-Coverage
# Date created:	   30 September 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-MakeMaker-Coverage
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Add a Makefile target to determine test coverage using Devel::Cover

BUILD_DEPENDS=	p5-Devel-Cover>=0:${PORTSDIR}/devel/p5-Devel-Cover \
		p5-Object-Accessor>=0:${PORTSDIR}/devel/p5-Object-Accessor \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::MakeMaker::Coverage.3

.include <bsd.port.mk>
