# Ports collection makefile for: ocaml-mysql
# Date created: 2011-09-25
# Whom: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mysql
PORTVERSION=	1.1.1
CATEGORIES=	databases
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/870/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	OCaml bindings to libmysqlclient

USE_GMAKE=		yes
USE_MYSQL=		yes

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

GNU_CONFIGURE=		yes

ALL_TARGET=		all opt

.if !defined(NOPORTDOCS)
ALL_TARGET+=		htdoc
PORTDOCS=		*
DOCSDIR=		${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mysql/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
