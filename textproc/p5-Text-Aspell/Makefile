# New ports collection makefile for:	textproc/p5-Text-Aspell
# Date created:				4 March 2005
# Whom:					lars.eggert@gmx.net
#
# $FreeBSD$
#

PORTNAME=	Text-Aspell
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the GNU Aspell library

BUILD_DEPENDS=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=INC=-I${LOCALBASE}/include \
		"LIBS=-L${LOCALBASE}/lib -laspell"

MAN3=		Text::Aspell.3

.include <bsd.port.mk>
