# ex:ts=8
# New ports collection makefile for:	POE::Component::Jabber
# Date created:		6 Aug 2004
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Jabber
PORTVERSION=	3.00
PORTREVISION=	1
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE Component for communicating over Jabber

BUILD_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Filter-Template>=0:${PORTSDIR}/devel/p5-Filter-Template \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-POE-Component-PubSub>=0:${PORTSDIR}/net/p5-POE-Component-PubSub \
		p5-POE-Component-SSLify>=0:${PORTSDIR}/security/p5-POE-Component-SSLify \
		p5-POE-Filter-XML>=0:${PORTSDIR}/textproc/p5-POE-Filter-XML \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes
CONFIGURE_ARGS=	</dev/null

PORTEXAMPLES=	*
MAN3=		POE::Component::Jabber.3 \
		POE::Component::Jabber::Events.3 \
		POE::Component::Jabber::J14.3 \
		POE::Component::Jabber::J2.3 \
		POE::Component::Jabber::Legacy.3 \
		POE::Component::Jabber::Protocol.3 \
		POE::Component::Jabber::ProtocolFactory.3 \
		POE::Component::Jabber::XMPP.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
