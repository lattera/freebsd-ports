# New ports collection Makefile for:		memgrep
# Date created:					22 February 2003
# Whom:						Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	memgrep
PORTVERSION=	0.8.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.hick.org/code/skape/memgrep/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to manipulate memory from running processes and core files

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386

PORTDOCS=	annotated.html doxygen.css doxygen.png examples.html files.html \
		functions.html group__memgrep.html index.html memgrep_8h-source.html \
		modules.html simple_8c-example.html  struct__core__memory__sections.html \
		struct__mem__ctx.html struct__mem__ctx__core__data.html \
		struct__memgrep__functions.html struct__memgrep__result.html\
		struct__memgrep__result__row.html struct__memgrep__result__row__dump.html \
		struct__memgrep__result__row__heap.html \
		struct__memgrep__result__row__replace.html \
		struct__memgrep__result__row__search.html struct__process__section__addrs.html

post-patch:
		@${REINPLACE_CMD} "s,-O3,,;s,FLAGS=,FLAGS+=," ${WRKSRC}/src/Makefile.in ${WRKSRC}/examples/Makefile.in

MAKE_ENV+=	FLAGS="${CFLAGS}"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
