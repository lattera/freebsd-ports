# New ports collection makefile for:	p5-HTML-FromANSI
# Date created:		2006-09-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-FromANSI
PORTVERSION=	2.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mark up ANSI sequences as HTML

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Term-VT102-Boundless>=0:${PORTSDIR}/devel/p5-Term-VT102-Boundless
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

PERL_CONFIGURE=	yes

MAN1=		ansi2html.1
MAN3=		HTML::FromANSI.3

.include <bsd.port.mk>
