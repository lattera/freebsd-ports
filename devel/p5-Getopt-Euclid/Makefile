# New ports collection makefile for:	devel/p5-Getopt-Euclid
# Date created:				28 Oct 2008
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Getopt-Euclid
PORTVERSION=	0.3.7
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Executable Uniform Command-Line Interface Descriptions

PERL_MODBUILD=	yes

MAN3=		Getopt::Euclid.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500900
BUILD_DEPENDS+=	p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
