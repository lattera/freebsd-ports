# New ports collection makefile for:	mailfront
# Date created:		03 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	mailfront
PORTVERSION=	1.18
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/ \
		http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	tarkhil@over.ru
COMMENT=	Mail server network protocol front-ends

LIB_DEPENDS=	cvm-v2client.2:${PORTSDIR}/security/cvm

WANT_QMAIL=	yes
QMAIL_PREFIX?=	/var/qmail
CFLAGS+=	-I${CVM_INC}
CFLAGS_SO=	${CFLAGS} -fPIC -shared -L${CVM_LIB}
LDFLAGS+=	-g -L${CVM_LIB} -rdynamic
BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
CVM_INC=	${LOCALBASE}/include
CVM_LIB=	${LOCALBASE}/lib
MODULES_DIR=	${PREFIX}/libexec/${PORTNAME}

DOCS=		NEWS README TODO *.html

.include <bsd.port.pre.mk>

do-configure:
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${PREFIX}/include"	> ${WRKSRC}/conf-include
	${ECHO_CMD} "${MODULES_DIR}"	> ${WRKSRC}/conf-modules
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${CFLAGS_SO}"> ${WRKSRC}/conf-ccso
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs
	${ECHO_CMD} "${QMAIL_PREFIX}"	> ${WRKSRC}/conf-qmail

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
