# New ports collection makefile for:	Class-DBI-Plugin-Pager
# Date created:		25 Oct 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin-Pager
PORTVERSION=	0.564
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to paged queries for CDBI

BUILD_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-SQL-Abstract>=1.61:${PORTSDIR}/databases/p5-SQL-Abstract \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Data-Page>=0:${PORTSDIR}/databases/p5-Data-Page \
		p5-Class-DBI-Plugin-AbstractCount>=0:${PORTSDIR}/databases/p5-Class-DBI-Plugin-AbstractCount
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Text-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes
MAN3=		Class::DBI::Plugin::Pager.3

.include <bsd.port.mk>
