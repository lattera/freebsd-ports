# New ports collection makefile for:   ocaml-net
# Date created:        01 March 2003
# Whom:                Stephane Legrand <stephane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	net
PORTVERSION=	3.5.1
CATEGORIES=	www
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml modules for Internet applications

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	ocaml-equeue-2* ocaml-netclient-0*

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
HAS_CONFIGURE=	yes

ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/netplex-admin \
		bin/ocamlrpcgen

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PKGNAMEPREFIX}${PORTNAME}
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

PORTDOCS=	*
PORTEXAMPLES=	*

OCAML_PKGDIRS=	netsys netshm equeue shell netstring rpc-generator \
		rpc pop smtp netclient netcgi2 netgssapi netplex \
		netcgi2-plex netcamlbox netmulticore rpc-auth-local
OCAML_LDLIBS=	${OCAML_PKGDIRS:S/^/${OCAML_SITELIBDIR}\//}

OPTIONS=	SSL "Enable SSL support" ON \
		NETHTTPD "Enable the integrated HTTP daemon" OFF \
		AUTH_DH "Enable Diffie-Hellman authorization support" OFF \
		GTK "Enable GTK support" OFF \
		GTK2 "Enable GTK2 support" OFF \
		APACHE "Enable Apache mod connector (experimental)" OFF \
		ZIP "Enable compression support" OFF \
		SCRAM "Enable SCRAM support" OFF

.include <bsd.port.options.mk>

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	-disable-ssl
.else
CONFIGURE_ARGS+=	-enable-ssl
BUILD_DEPENDS+=		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl
RUN_DEPENDS+=		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl
OCAML_PKGDIRS+=		equeue-ssl rpc-ssl
.endif

.if defined(WITH_NETHTTPD)
CONFIGURE_ARGS+=	-with-nethttpd
OCAML_PKGDIRS+=		nethttpd nethttpd-for-netcgi2
.else
CONFIGURE_ARGS+=	-without-nethttpd
.endif

.if defined(WITH_AUTH_DH)
CONFIGURE_ARGS+=	-with-rpc-auth-dh
BUILD_DEPENDS+=		${SA_DIR}/cryptgps/cryptgps.a:${PORTSDIR}/security/ocaml-cryptgps
RUN_DEPENDS+=		${SA_DIR}/cryptgps/cryptgps.a:${PORTSDIR}/security/ocaml-cryptgps
OCAML_PKGDIRS+=		rpc-auth-dh
.else
CONFIGURE_ARGS+=	-without-rpc-auth-dh
.endif

.if defined(WITH_GTK)
CONFIGURE_ARGS+=	-enable-gtk
BUILD_DEPENDS+=		lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk
RUN_DEPENDS+=		lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk
OCAML_PKGDIRS+=		equeue-gtk1
.else
CONFIGURE_ARGS+=	-disable-gtk
.endif

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=	-enable-gtk2
BUILD_DEPENDS+=		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
OCAML_PKGDIRS+=		equeue-gtk2
.else
CONFIGURE_ARGS+=	-disable-gtk2
.endif

.if defined(WITH_APACHE)
USE_APACHE=		22+
CONFIGURE_ARGS+=	-enable-apache -apxs ${APXS} -apache ${HTTPD}
OCAML_PKGDIRS+=		netcgi_apache
.else
CONFIGURE_ARGS+=	-disable-apache
.endif

.if defined(WITH_ZIP)
CONFIGURE_ARGS+=	-enable-zip
BUILD_DEPENDS+=		${SA_DIR}/zip/zip.a:${PORTSDIR}/archivers/ocaml-zip
RUN_DEPENDS+=		${SA_DIR}/zip/zip.a:${PORTSDIR}/archivers/ocaml-zip
OCAML_PKGDIRS+=		netzip
.else
CONFIGURE_ARGS+=	-disable-zip
.endif

.if defined(WITH_SCRAM)
CONFIGURE_ARGS+=	-enable-crypto
BUILD_DEPENDS+=		${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit
RUN_DEPENDS+=		${SA_DIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit
OCAML_PKGDIRS+=		netmech-scram
.else
CONFIGURE_ARGS+=	-disable-crypto
.endif

post-patch:
	${REINPLACE_CMD} -e '/\.libs/d' \
		${WRKSRC}/src/netcgi2-apache/Makefile.def
	${REINPLACE_CMD} -e 's/camlzip/zip/' \
		${WRKSRC}/configure \
		${WRKSRC}/src/netzip/META.in \
		${WRKSRC}/src/netzip/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
