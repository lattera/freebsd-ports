# ex:ts=8
# New ports collection makefile for:	netscript
# Date created:			May 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netscript
PORTVERSION=	1.7.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF \
		http://fakehalo.deadpig.org/%SUBDIR%/

EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable/multi-platform lightweight TCP socket scripting

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
ALL_TARGET=	gbsd
.else
ALL_TARGET=	bsd
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netscript ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${CHMOD} -R og+r ${EXAMPLESDIR}
	@${CHMOD} og+x ${EXAMPLESDIR}/gui ${EXAMPLESDIR}/ncurses
.endif

.include <bsd.port.post.mk>
