use ExtUtils::MakeMaker;

WriteMakefile (
);

sub MY::realclean {
'
realclean purge ::  clean realclean_subdirs uninstall
	- $(RM_F) \
	  $(MAKEFILE_OLD) $(FIRST_MAKEFILE) 
	- $(RM_RF) \
	  $(DISTVNAME) 
'
}

sub MY::install {
'
install_myself ::
	mkdir -p $(DESTINSTALLSITEARCH)/auto/sdbClient ;
	cp sdbClient/lib/lib*.so $(DESTINSTALLSITEARCH)/auto/sdbClient/ ;
install :: pure_install doc_install
	$(NOECHO) $(NOOP)
	rm -rf $(DESTINSTALLSITEARCH)/auto/$(NAME);

install_perl :: pure_perl_install doc_perl_install
	$(NOECHO) $(NOOP)

install_site :: pure_site_install doc_site_install
	$(NOECHO) $(NOOP)

install_vendor :: pure_vendor_install doc_vendor_install
	$(NOECHO) $(NOOP)

pure_install :: pure_$(INSTALLDIRS)_install
	$(NOECHO) $(NOOP)

doc_install :: doc_$(INSTALLDIRS)_install
	$(NOECHO) $(NOOP)

pure__install : pure_site_install
	$(NOECHO) $(ECHO) INSTALLDIRS not defined, defaulting to INSTALLDIRS=site

doc__install : doc_site_install
	$(NOECHO) $(ECHO) INSTALLDIRS not defined, defaulting to INSTALLDIRS=site

pure_perl_install :: all
	$(NOECHO) umask 022; $(MOD_INSTALL) \
		$(INST_LIB) $(DESTINSTALLPRIVLIB) \
		$(INST_ARCHLIB) $(DESTINSTALLARCHLIB) \
		$(INST_BIN) $(DESTINSTALLBIN) \
		$(INST_SCRIPT) $(DESTINSTALLSCRIPT) \
		$(INST_MAN1DIR) $(DESTINSTALLMAN1DIR) \
		$(INST_MAN3DIR) $(DESTINSTALLMAN3DIR)
	$(NOECHO) $(WARN_IF_OLD_PACKLIST) \
		$(SITEARCHEXP)/auto/$(FULLEXT)


pure_site_install :: all
	$(NOECHO) umask 02; $(MOD_INSTALL) \
		read $(SITEARCHEXP)/auto/$(FULLEXT)/.packlist \
		write $(DESTINSTALLSITEARCH)/auto/$(FULLEXT)/.packlist \
		$(INST_LIB) $(DESTINSTALLSITELIB) \
		$(INST_ARCHLIB) $(DESTINSTALLSITEARCH) \
		$(INST_BIN) $(DESTINSTALLSITEBIN) \
		$(INST_SCRIPT) $(DESTINSTALLSITESCRIPT) \
		$(INST_MAN1DIR) $(DESTINSTALLSITEMAN1DIR) \
		$(INST_MAN3DIR) $(DESTINSTALLSITEMAN3DIR)
	$(NOECHO) $(WARN_IF_OLD_PACKLIST) \
		$(PERL_ARCHLIB)/auto/$(FULLEXT)

pure_vendor_install :: all
	$(NOECHO) umask 022; $(MOD_INSTALL) \
		$(INST_LIB) $(DESTINSTALLVENDORLIB) \
		$(INST_ARCHLIB) $(DESTINSTALLVENDORARCH) \
		$(INST_BIN) $(DESTINSTALLVENDORBIN) \
		$(INST_SCRIPT) $(DESTINSTALLVENDORSCRIPT) \
		$(INST_MAN1DIR) $(DESTINSTALLVENDORMAN1DIR) \
		$(INST_MAN3DIR) $(DESTINSTALLVENDORMAN3DIR)

doc_perl_install :: all

doc_site_install :: all
	$(NOECHO) $(ECHO) Appending installation info to $(DESTINSTALLSITEARCH)/perllocal.pod
	-$(NOECHO) umask 02; $(MKPATH) $(DESTINSTALLSITEARCH)
	-$(NOECHO) umask 02; $(DOC_INSTALL) \
		"Module" "$(NAME)" \
		"installed into" "$(INSTALLSITELIB)" \
		LINKTYPE "$(LINKTYPE)" \
		VERSION "$(VERSION)" \
		EXE_FILES "$(EXE_FILES)" \
		>> $(DESTINSTALLSITEARCH)/perllocal.pod

doc_vendor_install :: all

uninstall ::
	rm -rf $(DESTINSTALLSITEARCH)/auto/sdbClient ;
	rm -rf $(DESTINSTALLSITEARCH)/auto/SequoiaDB ;
	rm -rf $(DESTINSTALLSITEARCH)/SequoiaDB ;
	rm -rf $(DESTINSTALLSITEARCH)/auto/$(NAME);
'
}

sub MY::subdirs {                                                                  
'                                                                                  
build_myself ::
	cd sdbClient && make PERL_LIB_DIR=$(INSTALLARCHLIB) && cd .. ;

subdirs :: build_myself

subdirs :: install_myself
	$(NOECHO) cd SequoiaDB-BSON && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-BSON-BINARY && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-BSON-BOOLEAN && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-BSON-CODE && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-BSON-MaxKey && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-BSON-MinKey && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-BSON-DATE && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-BSON-OID && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-BSON-REGEX && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-Collection && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-CollectionSpace && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-Cursor && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-Domain && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-Lob && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-Node && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-ReplicaGroup && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)

subdirs ::
	$(NOECHO) cd SequoiaDB-Sdb && $(MAKE) LD_RUN_PATH=$(DESTINSTALLSITEARCH)/auto/sdbClient/ $(USEMAKEFILE) $(FIRST_MAKEFILE) all $(PASTHRU)                                               
';                                                                                 
} 

