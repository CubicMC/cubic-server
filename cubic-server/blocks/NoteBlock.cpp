#include "NoteBlock.hpp"
#include <stdexcept>

namespace Blocks {
    namespace NoteBlock {
        BlockId toProtocol(Properties::Instrument instrument, Properties::Note note, Properties::Powered powered) {
            switch (instrument) {
            case Properties::Instrument::HARP:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 487;
                    case Properties::Powered::FALSE:
                        return 488;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 489;
                    case Properties::Powered::FALSE:
                        return 490;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 491;
                    case Properties::Powered::FALSE:
                        return 492;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 493;
                    case Properties::Powered::FALSE:
                        return 494;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 495;
                    case Properties::Powered::FALSE:
                        return 496;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 497;
                    case Properties::Powered::FALSE:
                        return 498;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 499;
                    case Properties::Powered::FALSE:
                        return 500;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 501;
                    case Properties::Powered::FALSE:
                        return 502;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 503;
                    case Properties::Powered::FALSE:
                        return 504;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 505;
                    case Properties::Powered::FALSE:
                        return 506;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 507;
                    case Properties::Powered::FALSE:
                        return 508;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 509;
                    case Properties::Powered::FALSE:
                        return 510;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 511;
                    case Properties::Powered::FALSE:
                        return 512;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 513;
                    case Properties::Powered::FALSE:
                        return 514;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 515;
                    case Properties::Powered::FALSE:
                        return 516;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 517;
                    case Properties::Powered::FALSE:
                        return 518;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 519;
                    case Properties::Powered::FALSE:
                        return 520;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 521;
                    case Properties::Powered::FALSE:
                        return 522;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 523;
                    case Properties::Powered::FALSE:
                        return 524;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 525;
                    case Properties::Powered::FALSE:
                        return 526;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 527;
                    case Properties::Powered::FALSE:
                        return 528;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 529;
                    case Properties::Powered::FALSE:
                        return 530;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 531;
                    case Properties::Powered::FALSE:
                        return 532;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 533;
                    case Properties::Powered::FALSE:
                        return 534;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 535;
                    case Properties::Powered::FALSE:
                        return 536;
                    }
                }
            case Properties::Instrument::BASEDRUM:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 537;
                    case Properties::Powered::FALSE:
                        return 538;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 539;
                    case Properties::Powered::FALSE:
                        return 540;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 541;
                    case Properties::Powered::FALSE:
                        return 542;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 543;
                    case Properties::Powered::FALSE:
                        return 544;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 545;
                    case Properties::Powered::FALSE:
                        return 546;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 547;
                    case Properties::Powered::FALSE:
                        return 548;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 549;
                    case Properties::Powered::FALSE:
                        return 550;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 551;
                    case Properties::Powered::FALSE:
                        return 552;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 553;
                    case Properties::Powered::FALSE:
                        return 554;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 555;
                    case Properties::Powered::FALSE:
                        return 556;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 557;
                    case Properties::Powered::FALSE:
                        return 558;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 559;
                    case Properties::Powered::FALSE:
                        return 560;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 561;
                    case Properties::Powered::FALSE:
                        return 562;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 563;
                    case Properties::Powered::FALSE:
                        return 564;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 565;
                    case Properties::Powered::FALSE:
                        return 566;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 567;
                    case Properties::Powered::FALSE:
                        return 568;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 569;
                    case Properties::Powered::FALSE:
                        return 570;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 571;
                    case Properties::Powered::FALSE:
                        return 572;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 573;
                    case Properties::Powered::FALSE:
                        return 574;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 575;
                    case Properties::Powered::FALSE:
                        return 576;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 577;
                    case Properties::Powered::FALSE:
                        return 578;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 579;
                    case Properties::Powered::FALSE:
                        return 580;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 581;
                    case Properties::Powered::FALSE:
                        return 582;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 583;
                    case Properties::Powered::FALSE:
                        return 584;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 585;
                    case Properties::Powered::FALSE:
                        return 586;
                    }
                }
            case Properties::Instrument::SNARE:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 587;
                    case Properties::Powered::FALSE:
                        return 588;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 589;
                    case Properties::Powered::FALSE:
                        return 590;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 591;
                    case Properties::Powered::FALSE:
                        return 592;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 593;
                    case Properties::Powered::FALSE:
                        return 594;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 595;
                    case Properties::Powered::FALSE:
                        return 596;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 597;
                    case Properties::Powered::FALSE:
                        return 598;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 599;
                    case Properties::Powered::FALSE:
                        return 600;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 601;
                    case Properties::Powered::FALSE:
                        return 602;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 603;
                    case Properties::Powered::FALSE:
                        return 604;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 605;
                    case Properties::Powered::FALSE:
                        return 606;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 607;
                    case Properties::Powered::FALSE:
                        return 608;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 609;
                    case Properties::Powered::FALSE:
                        return 610;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 611;
                    case Properties::Powered::FALSE:
                        return 612;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 613;
                    case Properties::Powered::FALSE:
                        return 614;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 615;
                    case Properties::Powered::FALSE:
                        return 616;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 617;
                    case Properties::Powered::FALSE:
                        return 618;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 619;
                    case Properties::Powered::FALSE:
                        return 620;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 621;
                    case Properties::Powered::FALSE:
                        return 622;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 623;
                    case Properties::Powered::FALSE:
                        return 624;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 625;
                    case Properties::Powered::FALSE:
                        return 626;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 627;
                    case Properties::Powered::FALSE:
                        return 628;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 629;
                    case Properties::Powered::FALSE:
                        return 630;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 631;
                    case Properties::Powered::FALSE:
                        return 632;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 633;
                    case Properties::Powered::FALSE:
                        return 634;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 635;
                    case Properties::Powered::FALSE:
                        return 636;
                    }
                }
            case Properties::Instrument::HAT:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 637;
                    case Properties::Powered::FALSE:
                        return 638;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 639;
                    case Properties::Powered::FALSE:
                        return 640;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 641;
                    case Properties::Powered::FALSE:
                        return 642;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 643;
                    case Properties::Powered::FALSE:
                        return 644;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 645;
                    case Properties::Powered::FALSE:
                        return 646;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 647;
                    case Properties::Powered::FALSE:
                        return 648;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 649;
                    case Properties::Powered::FALSE:
                        return 650;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 651;
                    case Properties::Powered::FALSE:
                        return 652;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 653;
                    case Properties::Powered::FALSE:
                        return 654;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 655;
                    case Properties::Powered::FALSE:
                        return 656;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 657;
                    case Properties::Powered::FALSE:
                        return 658;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 659;
                    case Properties::Powered::FALSE:
                        return 660;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 661;
                    case Properties::Powered::FALSE:
                        return 662;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 663;
                    case Properties::Powered::FALSE:
                        return 664;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 665;
                    case Properties::Powered::FALSE:
                        return 666;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 667;
                    case Properties::Powered::FALSE:
                        return 668;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 669;
                    case Properties::Powered::FALSE:
                        return 670;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 671;
                    case Properties::Powered::FALSE:
                        return 672;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 673;
                    case Properties::Powered::FALSE:
                        return 674;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 675;
                    case Properties::Powered::FALSE:
                        return 676;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 677;
                    case Properties::Powered::FALSE:
                        return 678;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 679;
                    case Properties::Powered::FALSE:
                        return 680;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 681;
                    case Properties::Powered::FALSE:
                        return 682;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 683;
                    case Properties::Powered::FALSE:
                        return 684;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 685;
                    case Properties::Powered::FALSE:
                        return 686;
                    }
                }
            case Properties::Instrument::BASS:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 687;
                    case Properties::Powered::FALSE:
                        return 688;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 689;
                    case Properties::Powered::FALSE:
                        return 690;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 691;
                    case Properties::Powered::FALSE:
                        return 692;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 693;
                    case Properties::Powered::FALSE:
                        return 694;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 695;
                    case Properties::Powered::FALSE:
                        return 696;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 697;
                    case Properties::Powered::FALSE:
                        return 698;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 699;
                    case Properties::Powered::FALSE:
                        return 700;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 701;
                    case Properties::Powered::FALSE:
                        return 702;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 703;
                    case Properties::Powered::FALSE:
                        return 704;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 705;
                    case Properties::Powered::FALSE:
                        return 706;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 707;
                    case Properties::Powered::FALSE:
                        return 708;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 709;
                    case Properties::Powered::FALSE:
                        return 710;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 711;
                    case Properties::Powered::FALSE:
                        return 712;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 713;
                    case Properties::Powered::FALSE:
                        return 714;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 715;
                    case Properties::Powered::FALSE:
                        return 716;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 717;
                    case Properties::Powered::FALSE:
                        return 718;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 719;
                    case Properties::Powered::FALSE:
                        return 720;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 721;
                    case Properties::Powered::FALSE:
                        return 722;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 723;
                    case Properties::Powered::FALSE:
                        return 724;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 725;
                    case Properties::Powered::FALSE:
                        return 726;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 727;
                    case Properties::Powered::FALSE:
                        return 728;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 729;
                    case Properties::Powered::FALSE:
                        return 730;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 731;
                    case Properties::Powered::FALSE:
                        return 732;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 733;
                    case Properties::Powered::FALSE:
                        return 734;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 735;
                    case Properties::Powered::FALSE:
                        return 736;
                    }
                }
            case Properties::Instrument::FLUTE:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 737;
                    case Properties::Powered::FALSE:
                        return 738;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 739;
                    case Properties::Powered::FALSE:
                        return 740;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 741;
                    case Properties::Powered::FALSE:
                        return 742;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 743;
                    case Properties::Powered::FALSE:
                        return 744;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 745;
                    case Properties::Powered::FALSE:
                        return 746;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 747;
                    case Properties::Powered::FALSE:
                        return 748;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 749;
                    case Properties::Powered::FALSE:
                        return 750;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 751;
                    case Properties::Powered::FALSE:
                        return 752;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 753;
                    case Properties::Powered::FALSE:
                        return 754;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 755;
                    case Properties::Powered::FALSE:
                        return 756;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 757;
                    case Properties::Powered::FALSE:
                        return 758;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 759;
                    case Properties::Powered::FALSE:
                        return 760;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 761;
                    case Properties::Powered::FALSE:
                        return 762;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 763;
                    case Properties::Powered::FALSE:
                        return 764;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 765;
                    case Properties::Powered::FALSE:
                        return 766;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 767;
                    case Properties::Powered::FALSE:
                        return 768;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 769;
                    case Properties::Powered::FALSE:
                        return 770;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 771;
                    case Properties::Powered::FALSE:
                        return 772;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 773;
                    case Properties::Powered::FALSE:
                        return 774;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 775;
                    case Properties::Powered::FALSE:
                        return 776;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 777;
                    case Properties::Powered::FALSE:
                        return 778;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 779;
                    case Properties::Powered::FALSE:
                        return 780;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 781;
                    case Properties::Powered::FALSE:
                        return 782;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 783;
                    case Properties::Powered::FALSE:
                        return 784;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 785;
                    case Properties::Powered::FALSE:
                        return 786;
                    }
                }
            case Properties::Instrument::BELL:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 787;
                    case Properties::Powered::FALSE:
                        return 788;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 789;
                    case Properties::Powered::FALSE:
                        return 790;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 791;
                    case Properties::Powered::FALSE:
                        return 792;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 793;
                    case Properties::Powered::FALSE:
                        return 794;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 795;
                    case Properties::Powered::FALSE:
                        return 796;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 797;
                    case Properties::Powered::FALSE:
                        return 798;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 799;
                    case Properties::Powered::FALSE:
                        return 800;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 801;
                    case Properties::Powered::FALSE:
                        return 802;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 803;
                    case Properties::Powered::FALSE:
                        return 804;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 805;
                    case Properties::Powered::FALSE:
                        return 806;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 807;
                    case Properties::Powered::FALSE:
                        return 808;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 809;
                    case Properties::Powered::FALSE:
                        return 810;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 811;
                    case Properties::Powered::FALSE:
                        return 812;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 813;
                    case Properties::Powered::FALSE:
                        return 814;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 815;
                    case Properties::Powered::FALSE:
                        return 816;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 817;
                    case Properties::Powered::FALSE:
                        return 818;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 819;
                    case Properties::Powered::FALSE:
                        return 820;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 821;
                    case Properties::Powered::FALSE:
                        return 822;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 823;
                    case Properties::Powered::FALSE:
                        return 824;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 825;
                    case Properties::Powered::FALSE:
                        return 826;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 827;
                    case Properties::Powered::FALSE:
                        return 828;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 829;
                    case Properties::Powered::FALSE:
                        return 830;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 831;
                    case Properties::Powered::FALSE:
                        return 832;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 833;
                    case Properties::Powered::FALSE:
                        return 834;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 835;
                    case Properties::Powered::FALSE:
                        return 836;
                    }
                }
            case Properties::Instrument::GUITAR:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 837;
                    case Properties::Powered::FALSE:
                        return 838;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 839;
                    case Properties::Powered::FALSE:
                        return 840;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 841;
                    case Properties::Powered::FALSE:
                        return 842;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 843;
                    case Properties::Powered::FALSE:
                        return 844;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 845;
                    case Properties::Powered::FALSE:
                        return 846;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 847;
                    case Properties::Powered::FALSE:
                        return 848;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 849;
                    case Properties::Powered::FALSE:
                        return 850;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 851;
                    case Properties::Powered::FALSE:
                        return 852;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 853;
                    case Properties::Powered::FALSE:
                        return 854;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 855;
                    case Properties::Powered::FALSE:
                        return 856;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 857;
                    case Properties::Powered::FALSE:
                        return 858;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 859;
                    case Properties::Powered::FALSE:
                        return 860;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 861;
                    case Properties::Powered::FALSE:
                        return 862;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 863;
                    case Properties::Powered::FALSE:
                        return 864;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 865;
                    case Properties::Powered::FALSE:
                        return 866;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 867;
                    case Properties::Powered::FALSE:
                        return 868;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 869;
                    case Properties::Powered::FALSE:
                        return 870;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 871;
                    case Properties::Powered::FALSE:
                        return 872;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 873;
                    case Properties::Powered::FALSE:
                        return 874;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 875;
                    case Properties::Powered::FALSE:
                        return 876;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 877;
                    case Properties::Powered::FALSE:
                        return 878;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 879;
                    case Properties::Powered::FALSE:
                        return 880;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 881;
                    case Properties::Powered::FALSE:
                        return 882;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 883;
                    case Properties::Powered::FALSE:
                        return 884;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 885;
                    case Properties::Powered::FALSE:
                        return 886;
                    }
                }
            case Properties::Instrument::CHIME:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 887;
                    case Properties::Powered::FALSE:
                        return 888;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 889;
                    case Properties::Powered::FALSE:
                        return 890;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 891;
                    case Properties::Powered::FALSE:
                        return 892;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 893;
                    case Properties::Powered::FALSE:
                        return 894;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 895;
                    case Properties::Powered::FALSE:
                        return 896;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 897;
                    case Properties::Powered::FALSE:
                        return 898;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 899;
                    case Properties::Powered::FALSE:
                        return 900;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 901;
                    case Properties::Powered::FALSE:
                        return 902;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 903;
                    case Properties::Powered::FALSE:
                        return 904;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 905;
                    case Properties::Powered::FALSE:
                        return 906;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 907;
                    case Properties::Powered::FALSE:
                        return 908;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 909;
                    case Properties::Powered::FALSE:
                        return 910;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 911;
                    case Properties::Powered::FALSE:
                        return 912;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 913;
                    case Properties::Powered::FALSE:
                        return 914;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 915;
                    case Properties::Powered::FALSE:
                        return 916;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 917;
                    case Properties::Powered::FALSE:
                        return 918;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 919;
                    case Properties::Powered::FALSE:
                        return 920;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 921;
                    case Properties::Powered::FALSE:
                        return 922;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 923;
                    case Properties::Powered::FALSE:
                        return 924;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 925;
                    case Properties::Powered::FALSE:
                        return 926;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 927;
                    case Properties::Powered::FALSE:
                        return 928;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 929;
                    case Properties::Powered::FALSE:
                        return 930;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 931;
                    case Properties::Powered::FALSE:
                        return 932;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 933;
                    case Properties::Powered::FALSE:
                        return 934;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 935;
                    case Properties::Powered::FALSE:
                        return 936;
                    }
                }
            case Properties::Instrument::XYLOPHONE:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 937;
                    case Properties::Powered::FALSE:
                        return 938;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 939;
                    case Properties::Powered::FALSE:
                        return 940;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 941;
                    case Properties::Powered::FALSE:
                        return 942;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 943;
                    case Properties::Powered::FALSE:
                        return 944;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 945;
                    case Properties::Powered::FALSE:
                        return 946;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 947;
                    case Properties::Powered::FALSE:
                        return 948;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 949;
                    case Properties::Powered::FALSE:
                        return 950;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 951;
                    case Properties::Powered::FALSE:
                        return 952;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 953;
                    case Properties::Powered::FALSE:
                        return 954;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 955;
                    case Properties::Powered::FALSE:
                        return 956;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 957;
                    case Properties::Powered::FALSE:
                        return 958;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 959;
                    case Properties::Powered::FALSE:
                        return 960;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 961;
                    case Properties::Powered::FALSE:
                        return 962;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 963;
                    case Properties::Powered::FALSE:
                        return 964;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 965;
                    case Properties::Powered::FALSE:
                        return 966;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 967;
                    case Properties::Powered::FALSE:
                        return 968;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 969;
                    case Properties::Powered::FALSE:
                        return 970;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 971;
                    case Properties::Powered::FALSE:
                        return 972;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 973;
                    case Properties::Powered::FALSE:
                        return 974;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 975;
                    case Properties::Powered::FALSE:
                        return 976;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 977;
                    case Properties::Powered::FALSE:
                        return 978;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 979;
                    case Properties::Powered::FALSE:
                        return 980;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 981;
                    case Properties::Powered::FALSE:
                        return 982;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 983;
                    case Properties::Powered::FALSE:
                        return 984;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 985;
                    case Properties::Powered::FALSE:
                        return 986;
                    }
                }
            case Properties::Instrument::IRON_XYLOPHONE:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 987;
                    case Properties::Powered::FALSE:
                        return 988;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 989;
                    case Properties::Powered::FALSE:
                        return 990;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 991;
                    case Properties::Powered::FALSE:
                        return 992;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 993;
                    case Properties::Powered::FALSE:
                        return 994;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 995;
                    case Properties::Powered::FALSE:
                        return 996;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 997;
                    case Properties::Powered::FALSE:
                        return 998;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 999;
                    case Properties::Powered::FALSE:
                        return 1000;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1001;
                    case Properties::Powered::FALSE:
                        return 1002;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1003;
                    case Properties::Powered::FALSE:
                        return 1004;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1005;
                    case Properties::Powered::FALSE:
                        return 1006;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1007;
                    case Properties::Powered::FALSE:
                        return 1008;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1009;
                    case Properties::Powered::FALSE:
                        return 1010;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1011;
                    case Properties::Powered::FALSE:
                        return 1012;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1013;
                    case Properties::Powered::FALSE:
                        return 1014;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1015;
                    case Properties::Powered::FALSE:
                        return 1016;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1017;
                    case Properties::Powered::FALSE:
                        return 1018;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1019;
                    case Properties::Powered::FALSE:
                        return 1020;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1021;
                    case Properties::Powered::FALSE:
                        return 1022;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1023;
                    case Properties::Powered::FALSE:
                        return 1024;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1025;
                    case Properties::Powered::FALSE:
                        return 1026;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1027;
                    case Properties::Powered::FALSE:
                        return 1028;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1029;
                    case Properties::Powered::FALSE:
                        return 1030;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1031;
                    case Properties::Powered::FALSE:
                        return 1032;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1033;
                    case Properties::Powered::FALSE:
                        return 1034;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1035;
                    case Properties::Powered::FALSE:
                        return 1036;
                    }
                }
            case Properties::Instrument::COW_BELL:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1037;
                    case Properties::Powered::FALSE:
                        return 1038;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1039;
                    case Properties::Powered::FALSE:
                        return 1040;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1041;
                    case Properties::Powered::FALSE:
                        return 1042;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1043;
                    case Properties::Powered::FALSE:
                        return 1044;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1045;
                    case Properties::Powered::FALSE:
                        return 1046;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1047;
                    case Properties::Powered::FALSE:
                        return 1048;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1049;
                    case Properties::Powered::FALSE:
                        return 1050;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1051;
                    case Properties::Powered::FALSE:
                        return 1052;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1053;
                    case Properties::Powered::FALSE:
                        return 1054;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1055;
                    case Properties::Powered::FALSE:
                        return 1056;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1057;
                    case Properties::Powered::FALSE:
                        return 1058;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1059;
                    case Properties::Powered::FALSE:
                        return 1060;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1061;
                    case Properties::Powered::FALSE:
                        return 1062;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1063;
                    case Properties::Powered::FALSE:
                        return 1064;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1065;
                    case Properties::Powered::FALSE:
                        return 1066;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1067;
                    case Properties::Powered::FALSE:
                        return 1068;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1069;
                    case Properties::Powered::FALSE:
                        return 1070;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1071;
                    case Properties::Powered::FALSE:
                        return 1072;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1073;
                    case Properties::Powered::FALSE:
                        return 1074;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1075;
                    case Properties::Powered::FALSE:
                        return 1076;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1077;
                    case Properties::Powered::FALSE:
                        return 1078;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1079;
                    case Properties::Powered::FALSE:
                        return 1080;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1081;
                    case Properties::Powered::FALSE:
                        return 1082;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1083;
                    case Properties::Powered::FALSE:
                        return 1084;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1085;
                    case Properties::Powered::FALSE:
                        return 1086;
                    }
                }
            case Properties::Instrument::DIDGERIDOO:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1087;
                    case Properties::Powered::FALSE:
                        return 1088;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1089;
                    case Properties::Powered::FALSE:
                        return 1090;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1091;
                    case Properties::Powered::FALSE:
                        return 1092;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1093;
                    case Properties::Powered::FALSE:
                        return 1094;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1095;
                    case Properties::Powered::FALSE:
                        return 1096;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1097;
                    case Properties::Powered::FALSE:
                        return 1098;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1099;
                    case Properties::Powered::FALSE:
                        return 1100;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1101;
                    case Properties::Powered::FALSE:
                        return 1102;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1103;
                    case Properties::Powered::FALSE:
                        return 1104;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1105;
                    case Properties::Powered::FALSE:
                        return 1106;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1107;
                    case Properties::Powered::FALSE:
                        return 1108;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1109;
                    case Properties::Powered::FALSE:
                        return 1110;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1111;
                    case Properties::Powered::FALSE:
                        return 1112;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1113;
                    case Properties::Powered::FALSE:
                        return 1114;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1115;
                    case Properties::Powered::FALSE:
                        return 1116;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1117;
                    case Properties::Powered::FALSE:
                        return 1118;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1119;
                    case Properties::Powered::FALSE:
                        return 1120;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1121;
                    case Properties::Powered::FALSE:
                        return 1122;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1123;
                    case Properties::Powered::FALSE:
                        return 1124;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1125;
                    case Properties::Powered::FALSE:
                        return 1126;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1127;
                    case Properties::Powered::FALSE:
                        return 1128;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1129;
                    case Properties::Powered::FALSE:
                        return 1130;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1131;
                    case Properties::Powered::FALSE:
                        return 1132;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1133;
                    case Properties::Powered::FALSE:
                        return 1134;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1135;
                    case Properties::Powered::FALSE:
                        return 1136;
                    }
                }
            case Properties::Instrument::BIT:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1137;
                    case Properties::Powered::FALSE:
                        return 1138;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1139;
                    case Properties::Powered::FALSE:
                        return 1140;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1141;
                    case Properties::Powered::FALSE:
                        return 1142;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1143;
                    case Properties::Powered::FALSE:
                        return 1144;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1145;
                    case Properties::Powered::FALSE:
                        return 1146;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1147;
                    case Properties::Powered::FALSE:
                        return 1148;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1149;
                    case Properties::Powered::FALSE:
                        return 1150;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1151;
                    case Properties::Powered::FALSE:
                        return 1152;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1153;
                    case Properties::Powered::FALSE:
                        return 1154;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1155;
                    case Properties::Powered::FALSE:
                        return 1156;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1157;
                    case Properties::Powered::FALSE:
                        return 1158;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1159;
                    case Properties::Powered::FALSE:
                        return 1160;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1161;
                    case Properties::Powered::FALSE:
                        return 1162;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1163;
                    case Properties::Powered::FALSE:
                        return 1164;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1165;
                    case Properties::Powered::FALSE:
                        return 1166;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1167;
                    case Properties::Powered::FALSE:
                        return 1168;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1169;
                    case Properties::Powered::FALSE:
                        return 1170;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1171;
                    case Properties::Powered::FALSE:
                        return 1172;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1173;
                    case Properties::Powered::FALSE:
                        return 1174;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1175;
                    case Properties::Powered::FALSE:
                        return 1176;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1177;
                    case Properties::Powered::FALSE:
                        return 1178;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1179;
                    case Properties::Powered::FALSE:
                        return 1180;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1181;
                    case Properties::Powered::FALSE:
                        return 1182;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1183;
                    case Properties::Powered::FALSE:
                        return 1184;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1185;
                    case Properties::Powered::FALSE:
                        return 1186;
                    }
                }
            case Properties::Instrument::BANJO:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1187;
                    case Properties::Powered::FALSE:
                        return 1188;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1189;
                    case Properties::Powered::FALSE:
                        return 1190;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1191;
                    case Properties::Powered::FALSE:
                        return 1192;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1193;
                    case Properties::Powered::FALSE:
                        return 1194;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1195;
                    case Properties::Powered::FALSE:
                        return 1196;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1197;
                    case Properties::Powered::FALSE:
                        return 1198;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1199;
                    case Properties::Powered::FALSE:
                        return 1200;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1201;
                    case Properties::Powered::FALSE:
                        return 1202;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1203;
                    case Properties::Powered::FALSE:
                        return 1204;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1205;
                    case Properties::Powered::FALSE:
                        return 1206;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1207;
                    case Properties::Powered::FALSE:
                        return 1208;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1209;
                    case Properties::Powered::FALSE:
                        return 1210;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1211;
                    case Properties::Powered::FALSE:
                        return 1212;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1213;
                    case Properties::Powered::FALSE:
                        return 1214;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1215;
                    case Properties::Powered::FALSE:
                        return 1216;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1217;
                    case Properties::Powered::FALSE:
                        return 1218;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1219;
                    case Properties::Powered::FALSE:
                        return 1220;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1221;
                    case Properties::Powered::FALSE:
                        return 1222;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1223;
                    case Properties::Powered::FALSE:
                        return 1224;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1225;
                    case Properties::Powered::FALSE:
                        return 1226;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1227;
                    case Properties::Powered::FALSE:
                        return 1228;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1229;
                    case Properties::Powered::FALSE:
                        return 1230;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1231;
                    case Properties::Powered::FALSE:
                        return 1232;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1233;
                    case Properties::Powered::FALSE:
                        return 1234;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1235;
                    case Properties::Powered::FALSE:
                        return 1236;
                    }
                }
            case Properties::Instrument::PLING:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1237;
                    case Properties::Powered::FALSE:
                        return 1238;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1239;
                    case Properties::Powered::FALSE:
                        return 1240;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1241;
                    case Properties::Powered::FALSE:
                        return 1242;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1243;
                    case Properties::Powered::FALSE:
                        return 1244;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1245;
                    case Properties::Powered::FALSE:
                        return 1246;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1247;
                    case Properties::Powered::FALSE:
                        return 1248;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1249;
                    case Properties::Powered::FALSE:
                        return 1250;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1251;
                    case Properties::Powered::FALSE:
                        return 1252;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1253;
                    case Properties::Powered::FALSE:
                        return 1254;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1255;
                    case Properties::Powered::FALSE:
                        return 1256;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1257;
                    case Properties::Powered::FALSE:
                        return 1258;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1259;
                    case Properties::Powered::FALSE:
                        return 1260;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1261;
                    case Properties::Powered::FALSE:
                        return 1262;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1263;
                    case Properties::Powered::FALSE:
                        return 1264;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1265;
                    case Properties::Powered::FALSE:
                        return 1266;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1267;
                    case Properties::Powered::FALSE:
                        return 1268;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1269;
                    case Properties::Powered::FALSE:
                        return 1270;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1271;
                    case Properties::Powered::FALSE:
                        return 1272;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1273;
                    case Properties::Powered::FALSE:
                        return 1274;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1275;
                    case Properties::Powered::FALSE:
                        return 1276;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1277;
                    case Properties::Powered::FALSE:
                        return 1278;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1279;
                    case Properties::Powered::FALSE:
                        return 1280;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1281;
                    case Properties::Powered::FALSE:
                        return 1282;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1283;
                    case Properties::Powered::FALSE:
                        return 1284;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1285;
                    case Properties::Powered::FALSE:
                        return 1286;
                    }
                }
            case Properties::Instrument::ZOMBIE:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1287;
                    case Properties::Powered::FALSE:
                        return 1288;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1289;
                    case Properties::Powered::FALSE:
                        return 1290;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1291;
                    case Properties::Powered::FALSE:
                        return 1292;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1293;
                    case Properties::Powered::FALSE:
                        return 1294;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1295;
                    case Properties::Powered::FALSE:
                        return 1296;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1297;
                    case Properties::Powered::FALSE:
                        return 1298;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1299;
                    case Properties::Powered::FALSE:
                        return 1300;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1301;
                    case Properties::Powered::FALSE:
                        return 1302;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1303;
                    case Properties::Powered::FALSE:
                        return 1304;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1305;
                    case Properties::Powered::FALSE:
                        return 1306;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1307;
                    case Properties::Powered::FALSE:
                        return 1308;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1309;
                    case Properties::Powered::FALSE:
                        return 1310;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1311;
                    case Properties::Powered::FALSE:
                        return 1312;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1313;
                    case Properties::Powered::FALSE:
                        return 1314;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1315;
                    case Properties::Powered::FALSE:
                        return 1316;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1317;
                    case Properties::Powered::FALSE:
                        return 1318;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1319;
                    case Properties::Powered::FALSE:
                        return 1320;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1321;
                    case Properties::Powered::FALSE:
                        return 1322;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1323;
                    case Properties::Powered::FALSE:
                        return 1324;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1325;
                    case Properties::Powered::FALSE:
                        return 1326;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1327;
                    case Properties::Powered::FALSE:
                        return 1328;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1329;
                    case Properties::Powered::FALSE:
                        return 1330;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1331;
                    case Properties::Powered::FALSE:
                        return 1332;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1333;
                    case Properties::Powered::FALSE:
                        return 1334;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1335;
                    case Properties::Powered::FALSE:
                        return 1336;
                    }
                }
            case Properties::Instrument::SKELETON:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1337;
                    case Properties::Powered::FALSE:
                        return 1338;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1339;
                    case Properties::Powered::FALSE:
                        return 1340;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1341;
                    case Properties::Powered::FALSE:
                        return 1342;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1343;
                    case Properties::Powered::FALSE:
                        return 1344;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1345;
                    case Properties::Powered::FALSE:
                        return 1346;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1347;
                    case Properties::Powered::FALSE:
                        return 1348;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1349;
                    case Properties::Powered::FALSE:
                        return 1350;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1351;
                    case Properties::Powered::FALSE:
                        return 1352;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1353;
                    case Properties::Powered::FALSE:
                        return 1354;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1355;
                    case Properties::Powered::FALSE:
                        return 1356;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1357;
                    case Properties::Powered::FALSE:
                        return 1358;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1359;
                    case Properties::Powered::FALSE:
                        return 1360;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1361;
                    case Properties::Powered::FALSE:
                        return 1362;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1363;
                    case Properties::Powered::FALSE:
                        return 1364;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1365;
                    case Properties::Powered::FALSE:
                        return 1366;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1367;
                    case Properties::Powered::FALSE:
                        return 1368;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1369;
                    case Properties::Powered::FALSE:
                        return 1370;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1371;
                    case Properties::Powered::FALSE:
                        return 1372;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1373;
                    case Properties::Powered::FALSE:
                        return 1374;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1375;
                    case Properties::Powered::FALSE:
                        return 1376;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1377;
                    case Properties::Powered::FALSE:
                        return 1378;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1379;
                    case Properties::Powered::FALSE:
                        return 1380;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1381;
                    case Properties::Powered::FALSE:
                        return 1382;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1383;
                    case Properties::Powered::FALSE:
                        return 1384;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1385;
                    case Properties::Powered::FALSE:
                        return 1386;
                    }
                }
            case Properties::Instrument::CREEPER:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1387;
                    case Properties::Powered::FALSE:
                        return 1388;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1389;
                    case Properties::Powered::FALSE:
                        return 1390;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1391;
                    case Properties::Powered::FALSE:
                        return 1392;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1393;
                    case Properties::Powered::FALSE:
                        return 1394;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1395;
                    case Properties::Powered::FALSE:
                        return 1396;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1397;
                    case Properties::Powered::FALSE:
                        return 1398;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1399;
                    case Properties::Powered::FALSE:
                        return 1400;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1401;
                    case Properties::Powered::FALSE:
                        return 1402;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1403;
                    case Properties::Powered::FALSE:
                        return 1404;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1405;
                    case Properties::Powered::FALSE:
                        return 1406;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1407;
                    case Properties::Powered::FALSE:
                        return 1408;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1409;
                    case Properties::Powered::FALSE:
                        return 1410;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1411;
                    case Properties::Powered::FALSE:
                        return 1412;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1413;
                    case Properties::Powered::FALSE:
                        return 1414;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1415;
                    case Properties::Powered::FALSE:
                        return 1416;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1417;
                    case Properties::Powered::FALSE:
                        return 1418;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1419;
                    case Properties::Powered::FALSE:
                        return 1420;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1421;
                    case Properties::Powered::FALSE:
                        return 1422;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1423;
                    case Properties::Powered::FALSE:
                        return 1424;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1425;
                    case Properties::Powered::FALSE:
                        return 1426;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1427;
                    case Properties::Powered::FALSE:
                        return 1428;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1429;
                    case Properties::Powered::FALSE:
                        return 1430;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1431;
                    case Properties::Powered::FALSE:
                        return 1432;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1433;
                    case Properties::Powered::FALSE:
                        return 1434;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1435;
                    case Properties::Powered::FALSE:
                        return 1436;
                    }
                }
            case Properties::Instrument::DRAGON:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1437;
                    case Properties::Powered::FALSE:
                        return 1438;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1439;
                    case Properties::Powered::FALSE:
                        return 1440;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1441;
                    case Properties::Powered::FALSE:
                        return 1442;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1443;
                    case Properties::Powered::FALSE:
                        return 1444;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1445;
                    case Properties::Powered::FALSE:
                        return 1446;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1447;
                    case Properties::Powered::FALSE:
                        return 1448;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1449;
                    case Properties::Powered::FALSE:
                        return 1450;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1451;
                    case Properties::Powered::FALSE:
                        return 1452;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1453;
                    case Properties::Powered::FALSE:
                        return 1454;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1455;
                    case Properties::Powered::FALSE:
                        return 1456;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1457;
                    case Properties::Powered::FALSE:
                        return 1458;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1459;
                    case Properties::Powered::FALSE:
                        return 1460;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1461;
                    case Properties::Powered::FALSE:
                        return 1462;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1463;
                    case Properties::Powered::FALSE:
                        return 1464;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1465;
                    case Properties::Powered::FALSE:
                        return 1466;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1467;
                    case Properties::Powered::FALSE:
                        return 1468;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1469;
                    case Properties::Powered::FALSE:
                        return 1470;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1471;
                    case Properties::Powered::FALSE:
                        return 1472;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1473;
                    case Properties::Powered::FALSE:
                        return 1474;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1475;
                    case Properties::Powered::FALSE:
                        return 1476;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1477;
                    case Properties::Powered::FALSE:
                        return 1478;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1479;
                    case Properties::Powered::FALSE:
                        return 1480;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1481;
                    case Properties::Powered::FALSE:
                        return 1482;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1483;
                    case Properties::Powered::FALSE:
                        return 1484;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1485;
                    case Properties::Powered::FALSE:
                        return 1486;
                    }
                }
            case Properties::Instrument::WITHER_SKELETON:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1487;
                    case Properties::Powered::FALSE:
                        return 1488;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1489;
                    case Properties::Powered::FALSE:
                        return 1490;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1491;
                    case Properties::Powered::FALSE:
                        return 1492;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1493;
                    case Properties::Powered::FALSE:
                        return 1494;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1495;
                    case Properties::Powered::FALSE:
                        return 1496;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1497;
                    case Properties::Powered::FALSE:
                        return 1498;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1499;
                    case Properties::Powered::FALSE:
                        return 1500;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1501;
                    case Properties::Powered::FALSE:
                        return 1502;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1503;
                    case Properties::Powered::FALSE:
                        return 1504;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1505;
                    case Properties::Powered::FALSE:
                        return 1506;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1507;
                    case Properties::Powered::FALSE:
                        return 1508;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1509;
                    case Properties::Powered::FALSE:
                        return 1510;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1511;
                    case Properties::Powered::FALSE:
                        return 1512;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1513;
                    case Properties::Powered::FALSE:
                        return 1514;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1515;
                    case Properties::Powered::FALSE:
                        return 1516;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1517;
                    case Properties::Powered::FALSE:
                        return 1518;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1519;
                    case Properties::Powered::FALSE:
                        return 1520;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1521;
                    case Properties::Powered::FALSE:
                        return 1522;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1523;
                    case Properties::Powered::FALSE:
                        return 1524;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1525;
                    case Properties::Powered::FALSE:
                        return 1526;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1527;
                    case Properties::Powered::FALSE:
                        return 1528;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1529;
                    case Properties::Powered::FALSE:
                        return 1530;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1531;
                    case Properties::Powered::FALSE:
                        return 1532;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1533;
                    case Properties::Powered::FALSE:
                        return 1534;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1535;
                    case Properties::Powered::FALSE:
                        return 1536;
                    }
                }
            case Properties::Instrument::PIGLIN:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1537;
                    case Properties::Powered::FALSE:
                        return 1538;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1539;
                    case Properties::Powered::FALSE:
                        return 1540;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1541;
                    case Properties::Powered::FALSE:
                        return 1542;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1543;
                    case Properties::Powered::FALSE:
                        return 1544;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1545;
                    case Properties::Powered::FALSE:
                        return 1546;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1547;
                    case Properties::Powered::FALSE:
                        return 1548;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1549;
                    case Properties::Powered::FALSE:
                        return 1550;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1551;
                    case Properties::Powered::FALSE:
                        return 1552;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1553;
                    case Properties::Powered::FALSE:
                        return 1554;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1555;
                    case Properties::Powered::FALSE:
                        return 1556;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1557;
                    case Properties::Powered::FALSE:
                        return 1558;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1559;
                    case Properties::Powered::FALSE:
                        return 1560;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1561;
                    case Properties::Powered::FALSE:
                        return 1562;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1563;
                    case Properties::Powered::FALSE:
                        return 1564;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1565;
                    case Properties::Powered::FALSE:
                        return 1566;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1567;
                    case Properties::Powered::FALSE:
                        return 1568;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1569;
                    case Properties::Powered::FALSE:
                        return 1570;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1571;
                    case Properties::Powered::FALSE:
                        return 1572;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1573;
                    case Properties::Powered::FALSE:
                        return 1574;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1575;
                    case Properties::Powered::FALSE:
                        return 1576;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1577;
                    case Properties::Powered::FALSE:
                        return 1578;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1579;
                    case Properties::Powered::FALSE:
                        return 1580;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1581;
                    case Properties::Powered::FALSE:
                        return 1582;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1583;
                    case Properties::Powered::FALSE:
                        return 1584;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1585;
                    case Properties::Powered::FALSE:
                        return 1586;
                    }
                }
            case Properties::Instrument::CUSTOM_HEAD:
                switch (note) {
                case Properties::Note::ZERO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1587;
                    case Properties::Powered::FALSE:
                        return 1588;
                    }
                case Properties::Note::ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1589;
                    case Properties::Powered::FALSE:
                        return 1590;
                    }
                case Properties::Note::TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1591;
                    case Properties::Powered::FALSE:
                        return 1592;
                    }
                case Properties::Note::THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1593;
                    case Properties::Powered::FALSE:
                        return 1594;
                    }
                case Properties::Note::FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1595;
                    case Properties::Powered::FALSE:
                        return 1596;
                    }
                case Properties::Note::FIVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1597;
                    case Properties::Powered::FALSE:
                        return 1598;
                    }
                case Properties::Note::SIX:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1599;
                    case Properties::Powered::FALSE:
                        return 1600;
                    }
                case Properties::Note::SEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1601;
                    case Properties::Powered::FALSE:
                        return 1602;
                    }
                case Properties::Note::EIGHT:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1603;
                    case Properties::Powered::FALSE:
                        return 1604;
                    }
                case Properties::Note::NINE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1605;
                    case Properties::Powered::FALSE:
                        return 1606;
                    }
                case Properties::Note::TEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1607;
                    case Properties::Powered::FALSE:
                        return 1608;
                    }
                case Properties::Note::ELEVEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1609;
                    case Properties::Powered::FALSE:
                        return 1610;
                    }
                case Properties::Note::TWELVE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1611;
                    case Properties::Powered::FALSE:
                        return 1612;
                    }
                case Properties::Note::THIRTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1613;
                    case Properties::Powered::FALSE:
                        return 1614;
                    }
                case Properties::Note::FOURTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1615;
                    case Properties::Powered::FALSE:
                        return 1616;
                    }
                case Properties::Note::FIFTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1617;
                    case Properties::Powered::FALSE:
                        return 1618;
                    }
                case Properties::Note::SIXTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1619;
                    case Properties::Powered::FALSE:
                        return 1620;
                    }
                case Properties::Note::SEVENTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1621;
                    case Properties::Powered::FALSE:
                        return 1622;
                    }
                case Properties::Note::EIGHTEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1623;
                    case Properties::Powered::FALSE:
                        return 1624;
                    }
                case Properties::Note::NINETEEN:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1625;
                    case Properties::Powered::FALSE:
                        return 1626;
                    }
                case Properties::Note::TWENTY:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1627;
                    case Properties::Powered::FALSE:
                        return 1628;
                    }
                case Properties::Note::TWENTY_ONE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1629;
                    case Properties::Powered::FALSE:
                        return 1630;
                    }
                case Properties::Note::TWENTY_TWO:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1631;
                    case Properties::Powered::FALSE:
                        return 1632;
                    }
                case Properties::Note::TWENTY_THREE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1633;
                    case Properties::Powered::FALSE:
                        return 1634;
                    }
                case Properties::Note::TWENTY_FOUR:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 1635;
                    case Properties::Powered::FALSE:
                        return 1636;
                    }
                }
            }
            return 0;
        }
    }

}
