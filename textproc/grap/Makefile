# New ports collection makefile for:   grap
# Date created:        4 February 2000
# Whom:                faber@lunabase.org
#
# $FreeBSD$
#

PORTNAME=	grap
PORTVERSION=	1.44
CATEGORIES=	textproc graphics
MASTER_SITES=	http://www.lunabase.org/~faber/Vault/software/grap/

MAINTAINER=	faber@lunabase.org
COMMENT=	An implementation of Kernigan & Bentley's grap language

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-freebsd-ports

CONFLICTS_INSTALL=heirloom-doctools-[0-9]*

MAN1=		grap.1
PORTDOCS=	README CHANGES COPYRIGHT grap.man

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.doc \
		${MAN1PREFIX}/man/man1/${PORTNAME}.1
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/grap.defines ${WRKSRC}/grap.tex.defines \
		${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for d in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$d ${DOCSDIR}
.  endfor
.endif
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include <bsd.port.mk>
