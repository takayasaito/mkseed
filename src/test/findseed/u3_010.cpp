#include <iostream>
#include "test_ds.hpp"

namespace {

    class U3010 : public TestDS
    {
    protected:
        U3010() {
            IFNAME1 = (char *)"mir_001.txt";
            IFNAME2 = (char *)"utr3_010.txt";
            OFNAME1 = (char *)"test_output_10.txt";
            OFNAME2 = (char *)"test_ds10.txt";
        }
    };

    TEST_F(U3010, mrna_fasta) {
        read_files();

        EXPECT_EQ(1u, length(mrna_ids));

        const char *id1 = "hg18_refGene NM_004339 range=chr21:45093941-45095923 5'pad=0 3'pad=0 "
                "revComp=TRUE strand=- repeatMasking=none";
        EXPECT_STREQ(id1, seqan::toCString(mrna_ids[0]));

        EXPECT_EQ(1u, length(mrna_seqs));
        const char *seq1 = "AGCGCUCCAGCACAUCAGUCCCGACGCUUCCUGUGAGGUGCACGCUCCGC"
                "AGCCCAGCCCAGCCGGGAGACCACGUGGCCAUUGCGGUCUCCUGACCUUG"
                "GCCAGUGAACCUGCCAGCCUUCCAGGACAGGCGGCCGGAGAGCUGCCCCU"
                "GAAGGACAGUCCUCUCGUCUUGCAGACUGGUGACCUUCUAUUCCCUGUUC"
                "AUCUCUGUUUCUAGAUUUAGUCACUUGAAAUAAGAAAUCUUUGGGGUUUG"
                "GGCUUUUUUAUACUCUUCUCAGUUUGUGAAACGCUAACUGCACACGAAGC"
                "CGCCUGACGGCACCCAGCGCUGUGGCUGUCAUUCUCCCAGGGCAGAACCC"
                "UGCGUUUCUCUCUGUCCACUAACAAGCUUCACACGCAACACAGGGAAGUC"
                "GGUUUGACUUUUGUCAUGAGGAGAACUGACCAGCCCUCAUCAUUCCCCAU"
                "AAAACCACGGACAGCGUCUGUGUGCGCAUCUUGAGUCUUCACACCUGUUG"
                "ACUCACACGGCUUUUGCUGAUGACACGGGGCUCCAGUACACAGUCUGAUA"
                "AGGACUUAACGUCCUAACCUCAAUUGUAUUAAAUAGCAUUGGGGAAUAGC"
                "UAAACCUUUUUAAAAAAAUUUAUUGGAUUUUCCUCCCUGCUUAAAAGAUU"
                "UCACCAGAAAACCUUCAUAUAAAAAUUCAGGCCCUUUUUGGACAAUUUUU"
                "AAAAUUUGUAUCUUUACUAGAACAUGAGAAUCUUUUUCCCUUGGAAGCUU"
                "GAAUUAUAAAUGUGGUGUUUGGCCUGCCUCAGCAGCACCAGUUGACUGCU"
                "CGUGUGCCAGCGGUGUGGGGAGGACGGGGCAGGACGCUGCAGCUCUCUCC"
                "AGCCCUGUUGGCAUCCUCAGUGCCUGCAGGCCUCUCGCUGCCUGUUGGGC"
                "UGUCUGGGGGGUGGCCAUUUAGGGAUCGUGGGGACGGGGUCCACCCCAAG"
                "AAGAAAGAAAGGCCCGUCCACAGGCCCGGCUCUGGGCCACGUGCCCCGGA"
                "AGCAGGUGUGUCCAGAGUCAGCUGAGGGCUCUCCCCACACCACCCAGCAG"
                "GCGCUGGUGCUCCUUCUGCCUCAUGGGACCAGUCCAGCUUCCAGCCGCUC"
                "UGGCUCGAGGGUGGUCUGACCACUUCCUUCUGAGUGGGCUUCUCUGGGAG"
                "CUCUCCAGUGGCACUGCUGGACCUGCCCACGUUUCUGUAAAAUCAGGAUA"
                "CGUGGCUUUAGUAAGCAGACCAAGCGCUUCGUGGCAGGGAAAGCAGCGUG"
                "CGGGGAAGUCACUGAAAAGUGCUGCCUAAGGAAGUUUGGAAAUAGUCCCU"
                "GUUCCAGAUUGCCUUGAAUUUUAAAACAUUUUGCUUUGGGAAAGUAGGUC"
                "AGCAGCACCUAAGAUCAAGGAUGCGUUCCAUUUUCACACUUCACAGUCAU"
                "GAAAACUGAGAAGACUGUCUUCAGCGUGAACUAAAGUUCACAGGCAGAUC"
                "ACUGAUCCAGAACACUUCAAGAACUCGUCAAACAGCUCGAUAAGCCUUUU"
                "UGACUGUGUACAUCUGUACCGGGAAUAACAUUCCUAGGCUGAAAUUUCCA"
                "CAAAGAAUAGAACCUGUACCCAGUUCUUCAGGCUGAUUUCCCUGACCUCU"
                "UGGGCAUUUGUAUUUGUAGUAAAGUAUUGCAGAGAUUCCUAAGUAUUUUA"
                "UAGCAGCCAUCAAAAUUGGACUUUGUAUUGUUUAUUCAUAAAAGACACUU"
                "GGUAAUAGACUUCAGUGAACUCUGUAUGAAUGCAGUAGUGUGUGUGCAAA"
                "AUCCGCUUCCUGAGCGUAGGGUGCUGAGCUGGCGCUAGGGCUCGGUUGUG"
                "AAAUACAGCGUAGUCAGCCCUUGCGCUCAGUGUAGAAACCCACGUCUGUA"
                "AGGUCGGUCUUCGUCCAUCUGCUUUUUUCUGAAAUACACUAAGAGCAGCC"
                "ACAAAACUGUAACCUCAAGGAAACCAUAAAGCUUGGAGUGCCUUAAUUUU"
                "UAACCAGUUUCCAAUAAAACGGUUUACUACCUG";
        EXPECT_STREQ(seq1, seqan::toCString((seqan::CharString)mrna_seqs[0]));
    }

    TEST_F(U3010, comp_ngram) {
        comp_ngram();
    }

    TEST_F(U3010, comp_bruteforce) {
        comp_bruteforce();
    }

    TEST_F(U3010, comp_horspool) {
        comp_horspool();
    }

    TEST_F(U3010, comp_suffixarray) {
        comp_suffixarray();
    }
}