LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := icu

LOCAL_CFLAGS += -DU_COMMON_IMPLEMENTATION \
				-fexceptions
				
LOCAL_C_INCLUDES :=  \
					$(JNI_H_INCLUDE)  \
					$(LOCAL_PATH)      \
					$../../third_party/libpng \
					$../../third_party/icu/source/common \
					$../../third_party/icu/source/i18n \

#stubdata
LOCAL_SRC_FILES	+= ../../../third_party/icu/source/stubdata/stubdata.c \


			
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/icu/source/common/*.cpp)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)	
#					 			
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/icu/source/common/*.c)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#MY_FILES := $(foreach n, $(MY_FILES), $(if $(findstring uchar_props_data.c,$(n)),,$(n)))
#MY_FILES := $(foreach n, $(MY_FILES), $(if $(findstring ubidi_props_data.c,$(n)),,$(n)))
#LOCAL_SRC_FILES += $(MY_FILES)	

#common
LOCAL_SRC_FILES	+=  ../../../third_party/icu/source/common/bmpset.cpp  \
					../../../third_party/icu/source/common/brkeng.cpp \
					../../../third_party/icu/source/common/brkiter.cpp \
					../../../third_party/icu/source/common/bytestream.cpp \
					../../../third_party/icu/source/common/caniter.cpp \
					../../../third_party/icu/source/common/chariter.cpp \
					../../../third_party/icu/source/common/charstr.cpp \
					../../../third_party/icu/source/common/cmemory.c \
					../../../third_party/icu/source/common/cstring.c \
					../../../third_party/icu/source/common//cwchar.c \
					../../../third_party/icu/source/common/dictbe.cpp \
					../../../third_party/icu/source/common/dtintrv.cpp \
					../../../third_party/icu/source/common/errorcode.cpp \
					../../../third_party/icu/source/common/filterednormalizer2.cpp \
					../../../third_party/icu/source/common/icudataver.c \
					../../../third_party/icu/source/common/icuplug.c \
					../../../third_party/icu/source/common/locavailable.cpp \
					../../../third_party/icu/source/common/locbased.cpp \
					../../../third_party/icu/source/common/locdispnames.cpp \
					../../../third_party/icu/source/common/locid.cpp \
					../../../third_party/icu/source/common/loclikely.cpp \
					../../../third_party/icu/source/common/locmap.c \
					../../../third_party/icu/source/common/locresdata.cpp \
					../../../third_party/icu/source/common/locutil.cpp \
					../../../third_party/icu/source/common/mutex.cpp \
					../../../third_party/icu/source/common/normalizer2.cpp \
					../../../third_party/icu/source/common/normalizer2impl.cpp \
					../../../third_party/icu/source/common/normlzr.cpp \
					../../../third_party/icu/source/common/parsepos.cpp \
					../../../third_party/icu/source/common/propname.cpp \
					../../../third_party/icu/source/common/propsvec.c \
					../../../third_party/icu/source/common/punycode.c \
					../../../third_party/icu/source/common/putil.c \
					../../../third_party/icu/source/common/rbbi.cpp \
					../../../third_party/icu/source/common/rbbidata.cpp \
					../../../third_party/icu/source/common/rbbinode.cpp \
					../../../third_party/icu/source/common/rbbirb.cpp \
					../../../third_party/icu/source/common/rbbiscan.cpp \
					../../../third_party/icu/source/common/rbbisetb.cpp \
					../../../third_party/icu/source/common/rbbistbl.cpp \
					../../../third_party/icu/source/common/rbbitblb.cpp \
					../../../third_party/icu/source/common/resbund.cpp \
					../../../third_party/icu/source/common/resbund_cnv.cpp \
					../../../third_party/icu/source/common/ruleiter.cpp \
					../../../third_party/icu/source/common/schriter.cpp \
					../../../third_party/icu/source/common/serv.cpp \
					../../../third_party/icu/source/common/servlk.cpp \
					../../../third_party/icu/source/common/servls.cpp \
					../../../third_party/icu/source/common/servnotf.cpp \
					../../../third_party/icu/source/common/servlkf.cpp \
					../../../third_party/icu/source/common/servrbf.cpp \
					../../../third_party/icu/source/common/servslkf.cpp \
					../../../third_party/icu/source/common/stringpiece.cpp \
					../../../third_party/icu/source/common/triedict.cpp \
					../../../third_party/icu/source/common/uarrsort.c \
					../../../third_party/icu/source/common/ubidi.c \
					../../../third_party/icu/source/common/ubidi_props.c \
					../../../third_party/icu/source/common/ubidiln.c \
					../../../third_party/icu/source/common/ubidiwrt.c \
					../../../third_party/icu/source/common/ubrk.cpp \
					../../../third_party/icu/source/common/ucase.c \
					../../../third_party/icu/source/common/ucasemap.c \
					../../../third_party/icu/source/common/ucat.c \
					../../../third_party/icu/source/common/uchar.c \
					../../../third_party/icu/source/common/uchriter.cpp \
					../../../third_party/icu/source/common/ucln_cmn.c \
					../../../third_party/icu/source/common/ucmndata.c \
					../../../third_party/icu/source/common/ucnv.c \
					../../../third_party/icu/source/common/ucnv_bld.c \
					../../../third_party/icu/source/common/ucnv_cb.c \
					../../../third_party/icu/source/common/ucnv_cnv.c \
					../../../third_party/icu/source/common/ucnv_err.c \
					../../../third_party/icu/source/common/ucnv_ext.c \
					../../../third_party/icu/source/common/ucnv_io.c \
					../../../third_party/icu/source/common/ucnv_lmb.c \
					../../../third_party/icu/source/common/ucnv_set.c \
					../../../third_party/icu/source/common/ucnv_u7.c \
					../../../third_party/icu/source/common/ucnv_u8.c \
					../../../third_party/icu/source/common/ucnv_u16.c \
					../../../third_party/icu/source/common/ucnv_u32.c \
					../../../third_party/icu/source/common/ucnv2022.c \
					../../../third_party/icu/source/common/ucnvbocu.c \
					../../../third_party/icu/source/common/ucnvdisp.c \
					../../../third_party/icu/source/common/ucnvhz.c \
					../../../third_party/icu/source/common/ucnvisci.c \
					../../../third_party/icu/source/common/ucnvlat1.c \
					../../../third_party/icu/source/common/ucnvmbcs.c \
					../../../third_party/icu/source/common/ucnvscsu.c \
					../../../third_party/icu/source/common/ucnvsel.cpp \
					../../../third_party/icu/source/common/ucol_swp.cpp \
					../../../third_party/icu/source/common/udata.cpp \
					../../../third_party/icu/source/common/udatamem.c \
					../../../third_party/icu/source/common/udataswp.c \
					../../../third_party/icu/source/common/uenum.c \
					../../../third_party/icu/source/common/uhash.c \
					../../../third_party/icu/source/common/uhash_us.cpp \
					../../../third_party/icu/source/common/uidna.cpp \
					../../../third_party/icu/source/common/uinit.c \
					../../../third_party/icu/source/common/uinvchar.c \
					../../../third_party/icu/source/common/uiter.cpp \
					../../../third_party/icu/source/common/ulist.c \
					../../../third_party/icu/source/common/uloc.c \
					../../../third_party/icu/source/common/uloc_tag.c \
					../../../third_party/icu/source/common/umapfile.c \
					../../../third_party/icu/source/common/umath.c \
					../../../third_party/icu/source/common/umutex.c \
					../../../third_party/icu/source/common/unames.c \
					../../../third_party/icu/source/common/unifilt.cpp \
					../../../third_party/icu/source/common/unifunct.cpp \
					../../../third_party/icu/source/common/uniset.cpp \
					../../../third_party/icu/source/common/uniset_props.cpp \
					../../../third_party/icu/source/common/unisetspan.cpp \
					../../../third_party/icu/source/common/unistr.cpp \
					../../../third_party/icu/source/common/unistr_case.cpp \
					../../../third_party/icu/source/common/unistr_cnv.cpp \
					../../../third_party/icu/source/common/unistr_props.cpp \
					../../../third_party/icu/source/common/unorm.cpp \
					../../../third_party/icu/source/common/unorm_it.c \
					../../../third_party/icu/source/common/unormcmp.cpp \
					../../../third_party/icu/source/common/uobject.cpp \
					../../../third_party/icu/source/common/uprops.cpp \
					../../../third_party/icu/source/common/ures_cnv.c \
					../../../third_party/icu/source/common/uresbund.c \
					../../../third_party/icu/source/common/uresdata.c \
					../../../third_party/icu/source/common/usc_impl.c \
					../../../third_party/icu/source/common/uscript.c \
					../../../third_party/icu/source/common/uset.cpp \
					../../../third_party/icu/source/common/uset_props.cpp \
					../../../third_party/icu/source/common/usetiter.cpp \
					../../../third_party/icu/source/common/ushape.c \
					../../../third_party/icu/source/common/usprep.cpp \
					../../../third_party/icu/source/common/ustack.cpp \
					../../../third_party/icu/source/common/ustr_cnv.c \
					../../../third_party/icu/source/common/ustr_wcs.c \
					../../../third_party/icu/source/common/ustrcase.c \
					../../../third_party/icu/source/common/ustrenum.cpp \
					../../../third_party/icu/source/common/ustrfmt.c \
					../../../third_party/icu/source/common/ustring.c \
					../../../third_party/icu/source/common/ustrtrns.c \
					../../../third_party/icu/source/common/utext.cpp \
					../../../third_party/icu/source/common/utf_impl.c \
					../../../third_party/icu/source/common/util.cpp \
					../../../third_party/icu/source/common/util_props.cpp \
					../../../third_party/icu/source/common/utrace.c \
					../../../third_party/icu/source/common/utrie.c \
					../../../third_party/icu/source/common/utrie2.cpp \
					../../../third_party/icu/source/common/utrie2_builder.c \
					../../../third_party/icu/source/common/uts46.cpp \
					../../../third_party/icu/source/common/utypes.c \
					../../../third_party/icu/source/common/uvector.cpp \
					../../../third_party/icu/source/common/uvectr32.cpp \
					../../../third_party/icu/source/common/uvectr64.cpp \
					../../../third_party/icu/source/common/wintz.c \
								
					

#i18n
LOCAL_SRC_FILES	+=  ../../../third_party/icu/source/i18n/anytrans.cpp \
					../../../third_party/icu/source/i18n/astro.cpp \
					../../../third_party/icu/source/i18n/basictz.cpp \
					../../../third_party/icu/source/i18n/bms.cpp \
					../../../third_party/icu/source/i18n/bmsearch.cpp \
					../../../third_party/icu/source/i18n/bocsu.c \
					../../../third_party/icu/source/i18n/brktrans.cpp \
					../../../third_party/icu/source/i18n/buddhcal.cpp \
					../../../third_party/icu/source/i18n/calendar.cpp \
					../../../third_party/icu/source/i18n/casetrn.cpp \
					../../../third_party/icu/source/i18n/cecal.cpp \
					../../../third_party/icu/source/i18n/chnsecal.cpp \
					../../../third_party/icu/source/i18n/choicfmt.cpp \
					../../../third_party/icu/source/i18n/coleitr.cpp \
					../../../third_party/icu/source/i18n/coll.cpp \
					../../../third_party/icu/source/i18n/colldata.cpp \
					../../../third_party/icu/source/i18n/coptccal.cpp \
					../../../third_party/icu/source/i18n/cpdtrans.cpp \
					../../../third_party/icu/source/i18n/csdetect.cpp \
					../../../third_party/icu/source/i18n/csmatch.cpp \
					../../../third_party/icu/source/i18n/csr2022.cpp \
					../../../third_party/icu/source/i18n/csrecog.cpp \
					../../../third_party/icu/source/i18n/csrmbcs.cpp \
					../../../third_party/icu/source/i18n/csrucode.cpp \
					../../../third_party/icu/source/i18n/csrutf8.cpp \
					../../../third_party/icu/source/i18n/curramt.cpp \
					../../../third_party/icu/source/i18n/currfmt.cpp \
					../../../third_party/icu/source/i18n/currpinf.cpp \
					../../../third_party/icu/source/i18n/currunit.cpp \
					../../../third_party/icu/source/i18n/datefmt.cpp \
					../../../third_party/icu/source/i18n/dcfmtsym.cpp \
					../../../third_party/icu/source/i18n/decContext.c \
					../../../third_party/icu/source/i18n/decimfmt.cpp \
					../../../third_party/icu/source/i18n/decNumber.c \
					../../../third_party/icu/source/i18n/digitlst.cpp \
					../../../third_party/icu/source/i18n/dtfmtsym.cpp \
					../../../third_party/icu/source/i18n/dtitvfmt.cpp \
					../../../third_party/icu/source/i18n/dtitvinf.cpp \
					../../../third_party/icu/source/i18n/dtptngen.cpp \
					../../../third_party/icu/source/i18n/dtrule.cpp \
					../../../third_party/icu/source/i18n/esctrn.cpp \
					../../../third_party/icu/source/i18n/ethpccal.cpp \
					../../../third_party/icu/source/i18n/fmtable.cpp \
					../../../third_party/icu/source/i18n/fmtable_cnv.cpp \
					../../../third_party/icu/source/i18n/format.cpp \
					../../../third_party/icu/source/i18n/fphdlimp.cpp \
					../../../third_party/icu/source/i18n/fpositer.cpp \
					../../../third_party/icu/source/i18n/funcrepl.cpp \
					../../../third_party/icu/source/i18n/gregocal.cpp \
					../../../third_party/icu/source/i18n/gregoimp.cpp \
					../../../third_party/icu/source/i18n/hebrwcal.cpp \
					../../../third_party/icu/source/i18n/indiancal.cpp \
					../../../third_party/icu/source/i18n/inputext.cpp \
					../../../third_party/icu/source/i18n/islamcal.cpp \
					../../../third_party/icu/source/i18n/japancal.cpp \
					../../../third_party/icu/source/i18n/locdspnm.cpp \
					../../../third_party/icu/source/i18n/measfmt.cpp \
					../../../third_party/icu/source/i18n/measure.cpp \
					../../../third_party/icu/source/i18n/msgfmt.cpp \
					../../../third_party/icu/source/i18n/name2uni.cpp \
					../../../third_party/icu/source/i18n/nfrs.cpp \
					../../../third_party/icu/source/i18n/nfrule.cpp \
					../../../third_party/icu/source/i18n/nfsubs.cpp \
					../../../third_party/icu/source/i18n/nortrans.cpp \
					../../../third_party/icu/source/i18n/nultrans.cpp \
					../../../third_party/icu/source/i18n/numfmt.cpp \
					../../../third_party/icu/source/i18n/numsys.cpp \
					../../../third_party/icu/source/i18n/olsontz.cpp \
					../../../third_party/icu/source/i18n/persncal.cpp \
					../../../third_party/icu/source/i18n/plurfmt.cpp \
					../../../third_party/icu/source/i18n/plurrule.cpp \
					../../../third_party/icu/source/i18n/quant.cpp \
					../../../third_party/icu/source/i18n/rbnf.cpp \
					../../../third_party/icu/source/i18n/rbt.cpp \
					../../../third_party/icu/source/i18n/rbt_data.cpp \
					../../../third_party/icu/source/i18n/rbt_pars.cpp \
					../../../third_party/icu/source/i18n/rbt_rule.cpp \
					../../../third_party/icu/source/i18n/rbt_set.cpp \
					../../../third_party/icu/source/i18n/rbtz.cpp \
					../../../third_party/icu/source/i18n/regexcmp.cpp \
					../../../third_party/icu/source/i18n/regexst.cpp \
					../../../third_party/icu/source/i18n/reldtfmt.cpp \
					../../../third_party/icu/source/i18n/rematch.cpp \
					../../../third_party/icu/source/i18n/remtrans.cpp \
					../../../third_party/icu/source/i18n/repattrn.cpp \
					../../../third_party/icu/source/i18n/search.cpp \
					../../../third_party/icu/source/i18n/selfmt.cpp \
					../../../third_party/icu/source/i18n/simpletz.cpp \
					../../../third_party/icu/source/i18n/smpdtfmt.cpp \
					../../../third_party/icu/source/i18n/sortkey.cpp \
					../../../third_party/icu/source/i18n/strmatch.cpp \
					../../../third_party/icu/source/i18n/strrepl.cpp \
					../../../third_party/icu/source/i18n/stsearch.cpp \
					../../../third_party/icu/source/i18n/taiwncal.cpp \
					../../../third_party/icu/source/i18n/tblcoll.cpp \
					../../../third_party/icu/source/i18n/timezone.cpp \
					../../../third_party/icu/source/i18n/titletrn.cpp \
					../../../third_party/icu/source/i18n/tmunit.cpp \
					../../../third_party/icu/source/i18n/tmutamt.cpp \
					../../../third_party/icu/source/i18n/tmutfmt.cpp \
					../../../third_party/icu/source/i18n/tolowtrn.cpp \
					../../../third_party/icu/source/i18n/toupptrn.cpp \
					../../../third_party/icu/source/i18n/translit.cpp \
					../../../third_party/icu/source/i18n/transreg.cpp \
					../../../third_party/icu/source/i18n/tridpars.cpp \
					../../../third_party/icu/source/i18n/tzrule.cpp \
					../../../third_party/icu/source/i18n/tztrans.cpp \
					../../../third_party/icu/source/i18n/ucal.cpp \
					../../../third_party/icu/source/i18n/ucln_in.c \
					../../../third_party/icu/source/i18n/ucol.cpp \
					../../../third_party/icu/source/i18n/ucol_bld.cpp \
					../../../third_party/icu/source/i18n/ucol_cnt.cpp \
					../../../third_party/icu/source/i18n/ucol_elm.cpp \
					../../../third_party/icu/source/i18n/ucol_res.cpp \
					../../../third_party/icu/source/i18n/ucol_sit.cpp \
					../../../third_party/icu/source/i18n/ucol_tok.cpp \
					../../../third_party/icu/source/i18n/ucol_wgt.cpp \
					../../../third_party/icu/source/i18n/ucoleitr.cpp \
					../../../third_party/icu/source/i18n/ucsdet.cpp \
					../../../third_party/icu/source/i18n/ucurr.cpp \
					../../../third_party/icu/source/i18n/udat.cpp \
					../../../third_party/icu/source/i18n/udatpg.cpp \
					../../../third_party/icu/source/i18n/ulocdata.c \
					../../../third_party/icu/source/i18n/umsg.cpp \
					../../../third_party/icu/source/i18n/unesctrn.cpp \
					../../../third_party/icu/source/i18n/uni2name.cpp \
					../../../third_party/icu/source/i18n/unum.cpp \
					../../../third_party/icu/source/i18n/uregex/cpp \
					../../../third_party/icu/source/i18n/uregexc.cpp \
					../../../third_party/icu/source/i18n/usearch.cpp \
					../../../third_party/icu/source/i18n/uspoof.cpp \
					../../../third_party/icu/source/i18n/uspoof_build.cpp \
					../../../third_party/icu/source/i18n/uspoof_conf.cpp \
					../../../third_party/icu/source/i18n/uspoof_impl.cpp \
					../../../third_party/icu/source/i18n/uspoof_wsconf.cpp \
					../../../third_party/icu/source/i18n/utmscale.c \
					../../../third_party/icu/source/i18n/utrans.cpp \
					../../../third_party/icu/source/i18n/vtzone.cpp \
					../../../third_party/icu/source/i18n/vzone.cpp \
					../../../third_party/icu/source/i18n/windtfmt.cpp \
					../../../third_party/icu/source/i18n/winnmfmt.cpp \
					../../../third_party/icu/source/i18n/wintzimpl.cpp \
					../../../third_party/icu/source/i18n/zonemeta.cpp \
					../../../third_party/icu/source/i18n/zrule.cpp \
					../../../third_party/icu/source/i18n/zstrfmt.cpp \
					../../../third_party/icu/source/i18n/ztrans.cpp \
					
					
					
					
					
				


#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


