#include <iostream>
#include "test_ds.hpp"

namespace {

    class TestDS8 : public TestDS
    {
    protected:
        TestDS8() {
            IFNAME1 = (char *)"hsa_mirbase_1.txt";
            IFNAME2 = (char *)"utr8.txt";
            OFNAME1 = (char *)"test_output_8.txt";
            OFNAME2 = (char *)"test_ds8.txt";
        }
    };

    TEST_F(TestDS8, mrna_fasta) {
        read_files();

        EXPECT_EQ(1u, length(mrna_ids));

        const char *id1 = "hg18_refGene NM_001259 range=chr7:92072173-92082389 5'pad=0 3'pad=0 "
                "revComp=TRUE strand=- repeatMasking=none";
        EXPECT_STREQ(id1, seqan::toCString(mrna_ids[0]));

        EXPECT_EQ(1u, length(mrna_seqs));
        const char *seq1 = "GGCCUCAGCAGCCGCCUUAAGCUGAUCCUGCGGAGAACACCCUUGGUGGC"
                "UUAUGGGUCCCCCUCAGCAAGCCCUACAGAGCUGUGGAGGAUUGCUAUCU"
                "GGAGGCCUUCCAGCUGCUGUCUUCUGGACAGGCUCUGCUUCUCCAAGGAA"
                "ACCGCCUAGUUUACUGUUUUGAAAUCAAUGCAAGAGUGAUUGCAGCUUUA"
                "UGUUCAUUUGUUUGUUUGUUUGUCUGUUUGUUUCAAGAACCUGGAAAAAU"
                "UCCAGAAGAAGAGAAGCUGCUGACCAAUUGUGCUGCCAUUUGAUUUUUCU"
                "AACCUUGAAUGCUGCCAGUGUGGAGUGGGUAAUCCAGGCACAGCUGAGUU"
                "AUGAUGUAAUCUCUCUGCAGCUGCCGGGCCUGAUUUGGUACUUUUGAGUG"
                "UGUGUGUGCAUGUGUGUGUGUGUGUGUGUGUGUGUGUGUGUGUAUGUGAG"
                "AGAUUCUGUGAUCUUUUAAAGUGUUACUUUUUGUAAACGACAAGAAUAAU"
                "UCAAUUUUAAAGACUCAAGGUGGUCAGUAAAUAACAGGCAUUUGUUCACU"
                "GAAGGUGAUUCACCAAAAUAGUCUUCUCAAAUUAGAAAGUUAACCCCAUG"
                "UCCUCAGCAUUUCUUUUCUGGCCAAAAGCAGUAAAUUUGCUAGCAGUAAA"
                "AGAUGAAGUUUUAUACACACAGCAAAAAGGAGAAAAAAUUCUAGUAUAUU"
                "UUAAGAGAUGUGCAUGCAUUCUAUUUAGUCUUCAGAAUGCUGAAUUUACU"
                "UGUUGUAAGUCUAUUUUAACCUUCUGUAUGACAUCAUGCUUUAUCAUUUC"
                "UUUUGGAAAAUAGCCUGUAAGCUUUUUAUUACUUGCUAUAGGUUUAGGGA"
                "GUGUACCUCAGAUAGAUUUUAAAAAAAAGAAUAGAAAGCCUUUAUUUCCU"
                "GGUUUGAAAUUCCUUUCUUCCCUUUUUUUGUUGUUGUUAUUGUUGUUUGU"
                "UGUUGUUAUUUUGUUUUUGUUUUUAGGAAUUUGUCAGAAACUCUUUCCUG"
                "UUUUGGUUUGGAGAGUAGUUCUCUCUAACUAGAGACAGGAGUGGCCUUGA"
                "AAUUUUCCUCAUCUAUUACACUGUACUUUCUGCCACACACUGCCUUGUUG"
                "GCAAAGUAUCCAUCUUGUCUAUCUCCCGGCACUUCUGAAAUAUAUUGCUA"
                "CCAUUGUAUAACUAAUAACAGAUUGCUUAAGCUGUUCCCAUGCACCACCU"
                "GUUUGCUUGCUUUCAAUGAACCUUUCAUAAAUUCGCAGUCUCAGCUUAUG"
                "GUUUAUGGCCUCGAUUCUGCAAACCUAACAGGGUCACAUAUGUUCUCUAA"
                "UGCAGUCCUUCUACCUGGUGUUUACUUUUGUUACCUAAAUAAUGAGUAGG"
                "AUCUUGUUUUGUUUUAUCACCAGCACACAGAUUGCUAUAAACUGUUACUU"
                "UGUGAAUUACAUUUUUAUAGAAGAUAUUUUCAGUGUCUUUACCUGAGGGU"
                "AUGUCUUUAGCUAUGUUUUAGGGCCAUACAUUUACUCUAUCAAAUGAUCU"
                "UUUCUCCAUCCCCCAGGCUGUGCUUAUUUCUAGUGCCUUGUGCUCACUCC"
                "UGCUCUCUACAGAGCCAGCCUGGCCUGGGCAUUGUAAACAGCUUUUCCUU"
                "UUUCUCUUACUGUUUUCUCUACAGUCCUUUAUAUUUCAUACCAUCUCUGC"
                "CUUAUAAGUGGUUUAGUGCUCAGUUGGCUCUAGUAACCAGAGGACACAGA"
                "AAGUAUCUUUUGGAAAGUUUAGCCACCUGUGCUUUCUGACUCAGAGUGCA"
                "UGCAACAGUUAGAUCAUGCAACAGUUAGAUUAUGUUUAGGGUUAGGAUUU"
                "UCAAAGAAUGGAGGUUGCUGCACUCAGAAAAUAAUUCAGAUCAUGUUUAU"
                "GCAUUAUUAAGUUGUACUGAAUUCUUUGCAGCUUAAUGUGAUAUAUGACU"
                "AUCUUGAACAAGAGAAAAAACUAGGAGAUGUUUCUCCUGAAGAGCUUUUG"
                "GGGUUGGGAACUAUUCUUUUUUAAUUGCUGUACUACUUAACAUUGUUCUA"
                "AUUCAGUAGCUUGAGGAACAGGAACAUUGUUUUCUAGAGCAAGAUAAUAA"
                "AGGAGAUGGGCCAUACAAAUGUUUUCUACUUUCGUUGUGACAACAUUGAU"
                "UAGGUGUUGUCAGUACUAUAAAUGCUUGAGAUAUAAUGAAUCCACAGCAU"
                "UCAAGGUCAGGUCUACUCAAAGUCUCACAUGGAAAAGUGAGUUCUGCCUU"
                "UCCUUUGAUCGAGGGUCAAAAUACAAAGACAUUUUUGCUAGGGCCUACAA"
                "AUUGAAUUUAAAAACUCACUGCACUGAUUCAUCUGAGCUUUUUGGUUAGU"
                "AUUCAUGGCUAGAGUGAACAUAGCUUUAGUUUUUGCUGUUGUAAAAGUGU"
                "UUUCAUAAGUUCACUCAAGAAAAAUGCAGCUGUUCUGAACUGGAAUUUUU"
                "CAGCAUUCUUUAGAAUUUUAAAUGAGUAGAGAGCUCAACUUUUAUUCCUA"
                "GCAUCUGCUUUUGACUCAUUUCUAGGCAGUGCUUAUGAAGAAAAAUUAAA"
                "GCACAAACAUUCUGGCAUUCAAUCGUUGGCAGAUUAUCUUCUGAUGACAC"
                "AGAAUGAAAGGGCAUCUCAGCCUCUCUGAACUUUGUAAAAAUCUGUCCCC"
                "AGUUCUUCCAUCGGUGUAGUUGUUGCAUUUGAGUGAAUACUCUCUUGAUU"
                "UAUGUAUUUUAUGUCCAGAUUCGCCAUUUCUGAAAUCCAGAUCCAACACA"
                "AGCAGUCUUGCCGUUAGGGCAUUUUGAAGCAGAUAGUAGAGUAAGAACUU"
                "AGUGACUACAGCUUAUUCUUCUGUAACAUAUGGUUUCAAACAUCUUUGCC"
                "AAAAGCUAAGCAGUGGUGAACUGAAAAGGGCAUAUUGCCCCAAGGUUACA"
                "CUGAAGCAGCUCAUAGCAAGUUAAAAUAUUGUGACAGAUUUGAAAUCAUG"
                "UUUGAAUUUCAUAGUAGGACCAGUACAAGAAUGUCCCUGCUAGUUUCUGU"
                "UUGAUGUUUGGUUCUGGCGGCUCAGGCAUUUUGGGAACUGUUGCACAGGG"
                "UGGAGUCAAAACAACCUACAUAUAAAAAAGAAACUUGUCCAUUUAGCUUU"
                "CAUAAGAAAUCCCAUGGCAAAGGGUAAUAAAAAGGACCUAAUCUUAAAAA"
                "UACAAUUUCUAAGCACUUGUAAGAACCCAGUGGGUUGGAGCCUCCCACUU"
                "UGUCCCUCCUUUGAAGUGGAUGGGAACUCAAGGUGCAAAGAACCUGUUUU"
                "GGAAGAAAGCUUGGGGCCAUUUCAGCCCCCUGUAUUCUCAUGAUUUUCUC"
                "UCAGGAAGCACACACUGUGAAUGGCAGACUUUUCAUUUAGCCCCAGGUGA"
                "CUUACUAAAAAUAGUUGAAAAUUAUUCACCUAAGAAUAGAAUCUCAGCAU"
                "UGUGUUAAAUAAAAAUGAAAGCUUUAGAAGGCAUGAGAUGUUCCUAUCUU"
                "AAAUAAAGCAUGUUUCUUUUCUAUAGAGAAAUGUAUAGUUUGACUCUCCA"
                "GAAUGUACUAUCCAUCUUGAUGAGAAAACUCUUAAAUAGUACCAAACAUU"
                "UUGAACUUUAAAUUAUGUAUUUAAAGUGAGUGUUUAAGAAACUGUAGCUG"
                "CUUCUUUUACAAGUGGUGCCUAUUAAAGUCAGUAAUGGCCAUUAUUGUUC"
                "CAUUGUGGAAAUUAAAUUAUGUAAGCUUCCUAAUAUCAUAAACAUAUUAA"
                "AAUUCUUCUAAAAUAUUGCUUUUCUUUUAAGUGACAAUUUGACUAUUCUU"
                "AUGAUAAGCACAUGAGAGUGUCUUACAUUUUCCAAAAGCAGGCUUUAAUU"
                "GCAUAGUUGAGUCUAGGAAAAAAUAAUGUUAAAAGUGAAUAUGCCACCAU"
                "AAUUACUUAAUUAUGUUAGUAUAGAAACUACAGAAUAUUUACCCUGGAAA"
                "GAAAAUAUUGGAAUGUUAUUAUAAACUCUUAGAUAUUUAUAUAAUUCAAA"
                "AGAAUGCAUGUUUCACAUUGUGACAGAUAAAGAUGUAUGAUUUCUAAGGC"
                "UUUAAAAAUUAUUCAUAAAACAGUGGGCAAUAGAUAAAGGAAAUUCUGGA"
                "GAAAAUGAAGGUAUUUAAAGGGUAGUUUCAAAGCUAUAUAUAUUUUGAAG"
                "GAUAUAUUCUUUAUGAACAAAUAUAUUGUAAAAAUUUAUACUAAGGUCAU"
                "CUGGUAACUGUGGGAUUAAUAUGGUCGAAAACAAAUGUUAUGGAGAAGCU"
                "GUCCCAAGCAAACUAAAUUACCUGUACUUUUUUCCCAUUUCAAGGGAAGA"
                "GGCAACCACAUGAAGCAAUACUUCUUACACAUGCCUAAGAACGUUCAUUG"
                "AAAAAAUAAAUUUUUAAAAGGCAUGUGUUUCCUAUGCCACCAAUACUUUU"
                "GAAAAAUUGUGAACCUUACCCAAAACCAUUUAUCAUGUCCAUUAAGUAUA"
                "UUUGGGUAUAUAAUUAGGAAGAUAUUUACAUGUUCCAUCUCCACAGUGGA"
                "AAAACUUAUUGAGGCUACCAAAGUGUGCCAAGAAAUGUAAGUCCUUAGAG"
                "UAAUUAGAAAUGCUGUUUUCCUCAAAAGCAUGAGAAACUAGCAUUUUCAU"
                "UUCUUAUUUACUCCCUUUCUAUAUCAAUGCAAUUCACAACCCAAUUUUAA"
                "UACAUCCCUAUAUCUCAAGCAUUUCUAUCUUGUACUUUUUCAGAAAAUAA"
                "ACCAAAAAUAAUCCUUUGGUCUCUCUAUCUUCUGACCUUUGUAAGCAACA"
                "GAAAUGUAAAAACAGAAGGGGUCCAAUUUUUACACGUUUUUUUCUCAAGU"
                "AGCCUUUCUGGGGAUUUUUAUUUUCUUAAUGAAGUGCCAAUCAGCUUUUC"
                "AAAAUGUUUUCUAUUUCUCAGCAUUUCCAGGAAGUGAUAACGUUUAGCUA"
                "AAUGAGUAGAAGUGGACUUCCUUCAACAUAUUGUUACCUUGUCUAGCCUU"
                "AGGAAGAAAACAAGAGCCACCUGAAAAUAAAUACAGGCUCUUUUCGAGCA"
                "UCUGCUGAAAUACUGUUACAGCAAUUUGAAGUUGAUGUGGUAGGAAAGGA"
                "AGGUGACUUUUCUUGCAAAAGUCUUUCUAAACAUUCACACUGUCCUAAGA"
                "GAUGAGCUUUCUUGUUUUAUUCCGGUAUAUUCCACAAGGUGGCACUUUUA"
                "GAGAAAAACAAAUCUGAUGAAGACUAAAGAGGUACUUCUAAAAGAGAUUU"
                "CAUUCUAACUUUAUUUUUCUGCGCAUAUUUAACUCUUUCCUAGCACUUGU"
                "UUUUUGGGAUGAUUAAUAGUCUCUAUAAUGUUCUGUAACUUCAAUAUUUU"
                "ACUUGUUACCUAGGUUCUGAACAAUUGUCUGCAAAUAAAUUGUUCUUAAG"
                "GAUGGAUAAUACACCCAUUUUGAUCAUUUAAGUAAAGAAAGCCUAGUCAU"
                "UCAUUCAGUCAAGAAAAAAUUUUUGAAGUACCCAGUUACCUUACUUUUCU"
                "AGAUUAAAACAGGCUUAGUUACUAAAAAGGCAGUCCUCAUCUGUGAACAG"
                "GAUAGUUUCGUUAGAAGUAUAAAACUCCUUUAGUGGCCCCAGUUAAAACA"
                "CACAUACCCUCUCUGCUGCUUUCAAAUUCCCUAGCAUGGUGGCCUUUCAA"
                "CAUUGAUUAAAUUUUAAAAUCCUAAUUUAAAGAUCAGGUGAGCAAAAUGA"
                "GUAGCACAUCAGUAAUUCAGUAGACAAAACUUUUGUCUGAAAAAUUGCUG"
                "UAUUGAAACAGAGCCCUAAAAUACCAAAAGACCAGGUAAUUUUAACAUUU"
                "GUGGAAUCACAAAUGUAAAUUCAUAAGAAGCUCUAAUUAAAAAAAAAAAG"
                "UCUGAAGUAUAUGAGCAUAACAACUUAGGAGUGUGUCUACAUACUUAACU"
                "UUUGAAGUUUUUUGGCAACUUUAUAUACUUUUUUUAAAUUUACAAGUCUA"
                "CUUAAAGACUUCUUAUACCCCAAAUGAUUAAGUUAAUUUUAGAGGUCACC"
                "UUUCUCACAGCAGUGUCACUUGAAAUUUAGUAGGGAAGGAUAUUGCAGUA"
                "UUUUUCAGUUUCCUUAGCACAGCACCACAGAAAGCAGCUUAUUCCUUUUG"
                "AGUGGCAGACACUCGACGGUGCCUGCCCAACUUUCCUCCUGAGUGGCAAG"
                "CAGAUGAGUCUCAGUAAUUCAUACUGAACCAAAAUGCCACAUACACUAGG"
                "GGCAGUCAGAAACUGGCUGAGAAAUCCCCCGCCUCAUUCGCCCCUCUGCU"
                "CCCAGGAACUAGAGUCCAGUUAAAGCCCCUAUGCGAAAGGCCGAAUUCCA"
                "CCCCAGGGUUUGUUAUAACAGUGGCCAGUCUGAACCCCAUUUGCUCGUGC"
                "UCAAAACUUGAUUCCCACUUGAAAGCCUUCCGGGCGCGCUGCCUCGUUGC"
                "CCCGCCCCUUUGGCAGGAGAGAGGCAGUGGGCGAGGCCGGGCUGGGGCCC"
                "CGCCUCCCACUCACCUGCCGGUGCCUGAAAUUAUGUGCGGCCCCGCGGGC"
                "UGCUUUCCGAGGUCAGAGUGCCCUGCUGCUGUCUCAGAGGCAUCUGUUCU";
        EXPECT_STREQ(seq1, seqan::toCString((seqan::CharString)mrna_seqs[0]));
    }

    TEST_F(TestDS8, comp_ngram) {
        comp_ngram();
    }

    TEST_F(TestDS8, comp_bruteforce) {
        comp_bruteforce();
    }

    TEST_F(TestDS8, comp_horspool) {
        comp_horspool();
    }

    TEST_F(TestDS8, comp_suffixarray) {
        comp_suffixarray();
    }
}