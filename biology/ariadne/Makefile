# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	ariadne
PORTVERSION=	1.3
CATEGORIES=	biology
MASTER_SITES=	http://www.well.ox.ac.uk/ariadne/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to compare protein sequences and profiles

WRKSRC=		${WRKDIR}/SRC-${PORTVERSION}
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}| ; \
		s|CC =|CC ?=| ; \
		s|CFLAGS =|CFLAGS +=| ; \
		s|-c $(OPTIMISE)|-c $(CFLAGS) $(OPTIMIZE)|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/ariadne ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/prospero ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
