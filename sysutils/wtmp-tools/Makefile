# New ports collection makefile for:	wtmp-tools
# Date created:				3 October 2005
# Whom:					Oleg M. Golovanov <olmi@rentech.ru>
#
# $FreeBSD$
#

PORTNAME=	wtmp-tools
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rentech.ru/archives/wtmp-tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The tool for editing wtmp files and converting into this format

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

MAN1=		t2w.1
MANCOMPRESSED=	yes

PORTDOCS=	*
PLIST_FILES=	bin/t2w

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^prefix.*=.*$$,prefix = ${PREFIX},' \
		${WRKSRC}/Makefile
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e '/$$(docdir)\/wtmp-tool/d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
