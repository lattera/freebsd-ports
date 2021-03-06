# Created by: ijliao
# $FreeBSD$

PORTNAME=	autodia
PORTVERSION=	2.03
PORTREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Tree/TEEJAY

DISTNAME=	Autodia-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic Dia XML - from Source Code and Data

BUILD_DEPENDS=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Inline-Java>=0:${PORTSDIR}/devel/p5-Inline-Java \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz \
		p5-VCG>=0:${PORTSDIR}/graphics/p5-VCG \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-SpringGraph>=0:${PORTSDIR}/graphics/p5-SpringGraph
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	autodia.pl.1 autodia_java.pl.1
MAN3=	Autodia.3 autodia.3 autodia_java.3 \
	Autodia::Diagram.3 \
	Autodia::Diagram::Class.3 \
	Autodia::Diagram::Component.3 \
	Autodia::Diagram::Dependancy.3 \
	Autodia::Diagram::Inheritance.3 \
	Autodia::Diagram::Object.3 \
	Autodia::Diagram::Superclass.3 \
	Autodia::Handler.3 \
	Autodia::Handler::Cpp.3 \
	Autodia::Handler::DBI.3 \
	Autodia::Handler::PHP.3 \
	Autodia::Handler::Perl.3 \
	Autodia::Handler::SQL.3 \
	Autodia::Handler::Torque.3 \
	Autodia::Handler::dia.3 \
	Autodia::Handler::umbrello.3

DOCS=	CHANGES COPYING CREDITS DEVELOP FAQ INSTALL MANIFEST README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
