# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	belvu
PORTVERSION=	2.29
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.cgb.ki.se/pub/prog/belvu/
DISTNAME=	${PORTNAME}.LIN_32bit_${PORTVERSION}
EXTRACT_SUFX=	#
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A viewer for multiple sequence alignments

USE_LINUX=	yes

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} bin/${DISTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		there are also executables for Alpha and Sparc \
		but they are for OSF and Solaris ... do they  \
		run on FreeBSD-Sparc and FreeBSD-alpha?
.endif

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin
	${BRANDELF} -t Linux ${PREFIX}/bin/${DISTNAME}
	( cd ${PREFIX}/bin && ${LN} -s ${DISTNAME} ${PORTNAME} )

.include <bsd.port.post.mk>
