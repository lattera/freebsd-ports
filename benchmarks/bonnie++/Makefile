# ex:ts=8
# New ports collection makefile for:	bonnie++
# Date created:			Mar 24, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bonnie++
PORTVERSION=	1.96
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/bonnie++/experimental/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Performance Test of Filesystem I/O

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

MAN1=	bon_csv2html.1 bon_csv2txt.1 generate_randfile.1
MAN8=	bonnie++.8 getc_putc.8 zcav.8

PORTDOCS=	readme.html

.include <bsd.port.options.mk>

pre-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/share/|${PREFIX}/share/|g' ${WRKSRC}/bonnie++.8

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/readme.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
