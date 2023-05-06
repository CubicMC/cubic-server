#include "NoteBlock.hpp"
namespace Blocks {
namespace NoteBlock {
BlockId toProtocol(Properties::Instrument instrument, Properties::Note note, Properties::Powered powered)
{
    switch (instrument) {
    case Properties::Instrument::HARP:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 487;
            case Properties::Powered::FALSE:
                return 488;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 489;
            case Properties::Powered::FALSE:
                return 490;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 491;
            case Properties::Powered::FALSE:
                return 492;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 493;
            case Properties::Powered::FALSE:
                return 494;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 495;
            case Properties::Powered::FALSE:
                return 496;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 497;
            case Properties::Powered::FALSE:
                return 498;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 499;
            case Properties::Powered::FALSE:
                return 500;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 501;
            case Properties::Powered::FALSE:
                return 502;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 503;
            case Properties::Powered::FALSE:
                return 504;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 505;
            case Properties::Powered::FALSE:
                return 506;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 507;
            case Properties::Powered::FALSE:
                return 508;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 509;
            case Properties::Powered::FALSE:
                return 510;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 511;
            case Properties::Powered::FALSE:
                return 512;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 513;
            case Properties::Powered::FALSE:
                return 514;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 515;
            case Properties::Powered::FALSE:
                return 516;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 517;
            case Properties::Powered::FALSE:
                return 518;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 519;
            case Properties::Powered::FALSE:
                return 520;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 521;
            case Properties::Powered::FALSE:
                return 522;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 523;
            case Properties::Powered::FALSE:
                return 524;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 525;
            case Properties::Powered::FALSE:
                return 526;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 527;
            case Properties::Powered::FALSE:
                return 528;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 529;
            case Properties::Powered::FALSE:
                return 530;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 531;
            case Properties::Powered::FALSE:
                return 532;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 533;
            case Properties::Powered::FALSE:
                return 534;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 535;
            case Properties::Powered::FALSE:
                return 536;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::BASEDRUM:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 537;
            case Properties::Powered::FALSE:
                return 538;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 539;
            case Properties::Powered::FALSE:
                return 540;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 541;
            case Properties::Powered::FALSE:
                return 542;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 543;
            case Properties::Powered::FALSE:
                return 544;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 545;
            case Properties::Powered::FALSE:
                return 546;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 547;
            case Properties::Powered::FALSE:
                return 548;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 549;
            case Properties::Powered::FALSE:
                return 550;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 551;
            case Properties::Powered::FALSE:
                return 552;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 553;
            case Properties::Powered::FALSE:
                return 554;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 555;
            case Properties::Powered::FALSE:
                return 556;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 557;
            case Properties::Powered::FALSE:
                return 558;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 559;
            case Properties::Powered::FALSE:
                return 560;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 561;
            case Properties::Powered::FALSE:
                return 562;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 563;
            case Properties::Powered::FALSE:
                return 564;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 565;
            case Properties::Powered::FALSE:
                return 566;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 567;
            case Properties::Powered::FALSE:
                return 568;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 569;
            case Properties::Powered::FALSE:
                return 570;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 571;
            case Properties::Powered::FALSE:
                return 572;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 573;
            case Properties::Powered::FALSE:
                return 574;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 575;
            case Properties::Powered::FALSE:
                return 576;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 577;
            case Properties::Powered::FALSE:
                return 578;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 579;
            case Properties::Powered::FALSE:
                return 580;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 581;
            case Properties::Powered::FALSE:
                return 582;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 583;
            case Properties::Powered::FALSE:
                return 584;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 585;
            case Properties::Powered::FALSE:
                return 586;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::SNARE:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 587;
            case Properties::Powered::FALSE:
                return 588;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 589;
            case Properties::Powered::FALSE:
                return 590;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 591;
            case Properties::Powered::FALSE:
                return 592;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 593;
            case Properties::Powered::FALSE:
                return 594;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 595;
            case Properties::Powered::FALSE:
                return 596;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 597;
            case Properties::Powered::FALSE:
                return 598;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 599;
            case Properties::Powered::FALSE:
                return 600;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 601;
            case Properties::Powered::FALSE:
                return 602;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 603;
            case Properties::Powered::FALSE:
                return 604;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 605;
            case Properties::Powered::FALSE:
                return 606;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 607;
            case Properties::Powered::FALSE:
                return 608;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 609;
            case Properties::Powered::FALSE:
                return 610;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 611;
            case Properties::Powered::FALSE:
                return 612;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 613;
            case Properties::Powered::FALSE:
                return 614;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 615;
            case Properties::Powered::FALSE:
                return 616;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 617;
            case Properties::Powered::FALSE:
                return 618;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 619;
            case Properties::Powered::FALSE:
                return 620;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 621;
            case Properties::Powered::FALSE:
                return 622;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 623;
            case Properties::Powered::FALSE:
                return 624;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 625;
            case Properties::Powered::FALSE:
                return 626;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 627;
            case Properties::Powered::FALSE:
                return 628;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 629;
            case Properties::Powered::FALSE:
                return 630;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 631;
            case Properties::Powered::FALSE:
                return 632;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 633;
            case Properties::Powered::FALSE:
                return 634;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 635;
            case Properties::Powered::FALSE:
                return 636;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::HAT:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 637;
            case Properties::Powered::FALSE:
                return 638;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 639;
            case Properties::Powered::FALSE:
                return 640;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 641;
            case Properties::Powered::FALSE:
                return 642;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 643;
            case Properties::Powered::FALSE:
                return 644;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 645;
            case Properties::Powered::FALSE:
                return 646;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 647;
            case Properties::Powered::FALSE:
                return 648;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 649;
            case Properties::Powered::FALSE:
                return 650;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 651;
            case Properties::Powered::FALSE:
                return 652;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 653;
            case Properties::Powered::FALSE:
                return 654;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 655;
            case Properties::Powered::FALSE:
                return 656;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 657;
            case Properties::Powered::FALSE:
                return 658;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 659;
            case Properties::Powered::FALSE:
                return 660;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 661;
            case Properties::Powered::FALSE:
                return 662;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 663;
            case Properties::Powered::FALSE:
                return 664;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 665;
            case Properties::Powered::FALSE:
                return 666;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 667;
            case Properties::Powered::FALSE:
                return 668;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 669;
            case Properties::Powered::FALSE:
                return 670;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 671;
            case Properties::Powered::FALSE:
                return 672;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 673;
            case Properties::Powered::FALSE:
                return 674;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 675;
            case Properties::Powered::FALSE:
                return 676;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 677;
            case Properties::Powered::FALSE:
                return 678;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 679;
            case Properties::Powered::FALSE:
                return 680;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 681;
            case Properties::Powered::FALSE:
                return 682;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 683;
            case Properties::Powered::FALSE:
                return 684;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 685;
            case Properties::Powered::FALSE:
                return 686;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::BASS:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 687;
            case Properties::Powered::FALSE:
                return 688;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 689;
            case Properties::Powered::FALSE:
                return 690;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 691;
            case Properties::Powered::FALSE:
                return 692;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 693;
            case Properties::Powered::FALSE:
                return 694;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 695;
            case Properties::Powered::FALSE:
                return 696;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 697;
            case Properties::Powered::FALSE:
                return 698;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 699;
            case Properties::Powered::FALSE:
                return 700;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 701;
            case Properties::Powered::FALSE:
                return 702;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 703;
            case Properties::Powered::FALSE:
                return 704;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 705;
            case Properties::Powered::FALSE:
                return 706;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 707;
            case Properties::Powered::FALSE:
                return 708;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 709;
            case Properties::Powered::FALSE:
                return 710;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 711;
            case Properties::Powered::FALSE:
                return 712;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 713;
            case Properties::Powered::FALSE:
                return 714;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 715;
            case Properties::Powered::FALSE:
                return 716;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 717;
            case Properties::Powered::FALSE:
                return 718;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 719;
            case Properties::Powered::FALSE:
                return 720;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 721;
            case Properties::Powered::FALSE:
                return 722;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 723;
            case Properties::Powered::FALSE:
                return 724;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 725;
            case Properties::Powered::FALSE:
                return 726;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 727;
            case Properties::Powered::FALSE:
                return 728;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 729;
            case Properties::Powered::FALSE:
                return 730;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 731;
            case Properties::Powered::FALSE:
                return 732;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 733;
            case Properties::Powered::FALSE:
                return 734;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 735;
            case Properties::Powered::FALSE:
                return 736;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::FLUTE:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 737;
            case Properties::Powered::FALSE:
                return 738;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 739;
            case Properties::Powered::FALSE:
                return 740;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 741;
            case Properties::Powered::FALSE:
                return 742;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 743;
            case Properties::Powered::FALSE:
                return 744;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 745;
            case Properties::Powered::FALSE:
                return 746;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 747;
            case Properties::Powered::FALSE:
                return 748;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 749;
            case Properties::Powered::FALSE:
                return 750;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 751;
            case Properties::Powered::FALSE:
                return 752;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 753;
            case Properties::Powered::FALSE:
                return 754;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 755;
            case Properties::Powered::FALSE:
                return 756;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 757;
            case Properties::Powered::FALSE:
                return 758;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 759;
            case Properties::Powered::FALSE:
                return 760;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 761;
            case Properties::Powered::FALSE:
                return 762;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 763;
            case Properties::Powered::FALSE:
                return 764;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 765;
            case Properties::Powered::FALSE:
                return 766;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 767;
            case Properties::Powered::FALSE:
                return 768;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 769;
            case Properties::Powered::FALSE:
                return 770;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 771;
            case Properties::Powered::FALSE:
                return 772;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 773;
            case Properties::Powered::FALSE:
                return 774;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 775;
            case Properties::Powered::FALSE:
                return 776;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 777;
            case Properties::Powered::FALSE:
                return 778;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 779;
            case Properties::Powered::FALSE:
                return 780;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 781;
            case Properties::Powered::FALSE:
                return 782;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 783;
            case Properties::Powered::FALSE:
                return 784;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 785;
            case Properties::Powered::FALSE:
                return 786;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::BELL:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 787;
            case Properties::Powered::FALSE:
                return 788;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 789;
            case Properties::Powered::FALSE:
                return 790;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 791;
            case Properties::Powered::FALSE:
                return 792;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 793;
            case Properties::Powered::FALSE:
                return 794;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 795;
            case Properties::Powered::FALSE:
                return 796;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 797;
            case Properties::Powered::FALSE:
                return 798;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 799;
            case Properties::Powered::FALSE:
                return 800;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 801;
            case Properties::Powered::FALSE:
                return 802;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 803;
            case Properties::Powered::FALSE:
                return 804;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 805;
            case Properties::Powered::FALSE:
                return 806;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 807;
            case Properties::Powered::FALSE:
                return 808;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 809;
            case Properties::Powered::FALSE:
                return 810;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 811;
            case Properties::Powered::FALSE:
                return 812;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 813;
            case Properties::Powered::FALSE:
                return 814;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 815;
            case Properties::Powered::FALSE:
                return 816;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 817;
            case Properties::Powered::FALSE:
                return 818;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 819;
            case Properties::Powered::FALSE:
                return 820;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 821;
            case Properties::Powered::FALSE:
                return 822;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 823;
            case Properties::Powered::FALSE:
                return 824;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 825;
            case Properties::Powered::FALSE:
                return 826;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 827;
            case Properties::Powered::FALSE:
                return 828;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 829;
            case Properties::Powered::FALSE:
                return 830;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 831;
            case Properties::Powered::FALSE:
                return 832;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 833;
            case Properties::Powered::FALSE:
                return 834;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 835;
            case Properties::Powered::FALSE:
                return 836;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::GUITAR:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 837;
            case Properties::Powered::FALSE:
                return 838;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 839;
            case Properties::Powered::FALSE:
                return 840;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 841;
            case Properties::Powered::FALSE:
                return 842;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 843;
            case Properties::Powered::FALSE:
                return 844;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 845;
            case Properties::Powered::FALSE:
                return 846;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 847;
            case Properties::Powered::FALSE:
                return 848;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 849;
            case Properties::Powered::FALSE:
                return 850;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 851;
            case Properties::Powered::FALSE:
                return 852;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 853;
            case Properties::Powered::FALSE:
                return 854;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 855;
            case Properties::Powered::FALSE:
                return 856;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 857;
            case Properties::Powered::FALSE:
                return 858;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 859;
            case Properties::Powered::FALSE:
                return 860;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 861;
            case Properties::Powered::FALSE:
                return 862;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 863;
            case Properties::Powered::FALSE:
                return 864;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 865;
            case Properties::Powered::FALSE:
                return 866;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 867;
            case Properties::Powered::FALSE:
                return 868;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 869;
            case Properties::Powered::FALSE:
                return 870;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 871;
            case Properties::Powered::FALSE:
                return 872;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 873;
            case Properties::Powered::FALSE:
                return 874;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 875;
            case Properties::Powered::FALSE:
                return 876;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 877;
            case Properties::Powered::FALSE:
                return 878;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 879;
            case Properties::Powered::FALSE:
                return 880;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 881;
            case Properties::Powered::FALSE:
                return 882;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 883;
            case Properties::Powered::FALSE:
                return 884;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 885;
            case Properties::Powered::FALSE:
                return 886;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::CHIME:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 887;
            case Properties::Powered::FALSE:
                return 888;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 889;
            case Properties::Powered::FALSE:
                return 890;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 891;
            case Properties::Powered::FALSE:
                return 892;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 893;
            case Properties::Powered::FALSE:
                return 894;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 895;
            case Properties::Powered::FALSE:
                return 896;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 897;
            case Properties::Powered::FALSE:
                return 898;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 899;
            case Properties::Powered::FALSE:
                return 900;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 901;
            case Properties::Powered::FALSE:
                return 902;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 903;
            case Properties::Powered::FALSE:
                return 904;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 905;
            case Properties::Powered::FALSE:
                return 906;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 907;
            case Properties::Powered::FALSE:
                return 908;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 909;
            case Properties::Powered::FALSE:
                return 910;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 911;
            case Properties::Powered::FALSE:
                return 912;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 913;
            case Properties::Powered::FALSE:
                return 914;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 915;
            case Properties::Powered::FALSE:
                return 916;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 917;
            case Properties::Powered::FALSE:
                return 918;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 919;
            case Properties::Powered::FALSE:
                return 920;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 921;
            case Properties::Powered::FALSE:
                return 922;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 923;
            case Properties::Powered::FALSE:
                return 924;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 925;
            case Properties::Powered::FALSE:
                return 926;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 927;
            case Properties::Powered::FALSE:
                return 928;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 929;
            case Properties::Powered::FALSE:
                return 930;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 931;
            case Properties::Powered::FALSE:
                return 932;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 933;
            case Properties::Powered::FALSE:
                return 934;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 935;
            case Properties::Powered::FALSE:
                return 936;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::XYLOPHONE:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 937;
            case Properties::Powered::FALSE:
                return 938;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 939;
            case Properties::Powered::FALSE:
                return 940;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 941;
            case Properties::Powered::FALSE:
                return 942;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 943;
            case Properties::Powered::FALSE:
                return 944;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 945;
            case Properties::Powered::FALSE:
                return 946;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 947;
            case Properties::Powered::FALSE:
                return 948;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 949;
            case Properties::Powered::FALSE:
                return 950;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 951;
            case Properties::Powered::FALSE:
                return 952;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 953;
            case Properties::Powered::FALSE:
                return 954;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 955;
            case Properties::Powered::FALSE:
                return 956;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 957;
            case Properties::Powered::FALSE:
                return 958;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 959;
            case Properties::Powered::FALSE:
                return 960;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 961;
            case Properties::Powered::FALSE:
                return 962;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 963;
            case Properties::Powered::FALSE:
                return 964;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 965;
            case Properties::Powered::FALSE:
                return 966;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 967;
            case Properties::Powered::FALSE:
                return 968;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 969;
            case Properties::Powered::FALSE:
                return 970;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 971;
            case Properties::Powered::FALSE:
                return 972;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 973;
            case Properties::Powered::FALSE:
                return 974;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 975;
            case Properties::Powered::FALSE:
                return 976;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 977;
            case Properties::Powered::FALSE:
                return 978;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 979;
            case Properties::Powered::FALSE:
                return 980;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 981;
            case Properties::Powered::FALSE:
                return 982;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 983;
            case Properties::Powered::FALSE:
                return 984;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 985;
            case Properties::Powered::FALSE:
                return 986;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::IRON_XYLOPHONE:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 987;
            case Properties::Powered::FALSE:
                return 988;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 989;
            case Properties::Powered::FALSE:
                return 990;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 991;
            case Properties::Powered::FALSE:
                return 992;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 993;
            case Properties::Powered::FALSE:
                return 994;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 995;
            case Properties::Powered::FALSE:
                return 996;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 997;
            case Properties::Powered::FALSE:
                return 998;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 999;
            case Properties::Powered::FALSE:
                return 1000;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1001;
            case Properties::Powered::FALSE:
                return 1002;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1003;
            case Properties::Powered::FALSE:
                return 1004;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1005;
            case Properties::Powered::FALSE:
                return 1006;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1007;
            case Properties::Powered::FALSE:
                return 1008;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1009;
            case Properties::Powered::FALSE:
                return 1010;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1011;
            case Properties::Powered::FALSE:
                return 1012;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1013;
            case Properties::Powered::FALSE:
                return 1014;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1015;
            case Properties::Powered::FALSE:
                return 1016;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1017;
            case Properties::Powered::FALSE:
                return 1018;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1019;
            case Properties::Powered::FALSE:
                return 1020;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1021;
            case Properties::Powered::FALSE:
                return 1022;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1023;
            case Properties::Powered::FALSE:
                return 1024;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1025;
            case Properties::Powered::FALSE:
                return 1026;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1027;
            case Properties::Powered::FALSE:
                return 1028;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1029;
            case Properties::Powered::FALSE:
                return 1030;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1031;
            case Properties::Powered::FALSE:
                return 1032;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1033;
            case Properties::Powered::FALSE:
                return 1034;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1035;
            case Properties::Powered::FALSE:
                return 1036;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::COW_BELL:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1037;
            case Properties::Powered::FALSE:
                return 1038;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1039;
            case Properties::Powered::FALSE:
                return 1040;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1041;
            case Properties::Powered::FALSE:
                return 1042;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1043;
            case Properties::Powered::FALSE:
                return 1044;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1045;
            case Properties::Powered::FALSE:
                return 1046;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1047;
            case Properties::Powered::FALSE:
                return 1048;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1049;
            case Properties::Powered::FALSE:
                return 1050;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1051;
            case Properties::Powered::FALSE:
                return 1052;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1053;
            case Properties::Powered::FALSE:
                return 1054;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1055;
            case Properties::Powered::FALSE:
                return 1056;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1057;
            case Properties::Powered::FALSE:
                return 1058;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1059;
            case Properties::Powered::FALSE:
                return 1060;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1061;
            case Properties::Powered::FALSE:
                return 1062;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1063;
            case Properties::Powered::FALSE:
                return 1064;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1065;
            case Properties::Powered::FALSE:
                return 1066;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1067;
            case Properties::Powered::FALSE:
                return 1068;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1069;
            case Properties::Powered::FALSE:
                return 1070;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1071;
            case Properties::Powered::FALSE:
                return 1072;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1073;
            case Properties::Powered::FALSE:
                return 1074;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1075;
            case Properties::Powered::FALSE:
                return 1076;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1077;
            case Properties::Powered::FALSE:
                return 1078;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1079;
            case Properties::Powered::FALSE:
                return 1080;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1081;
            case Properties::Powered::FALSE:
                return 1082;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1083;
            case Properties::Powered::FALSE:
                return 1084;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1085;
            case Properties::Powered::FALSE:
                return 1086;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::DIDGERIDOO:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1087;
            case Properties::Powered::FALSE:
                return 1088;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1089;
            case Properties::Powered::FALSE:
                return 1090;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1091;
            case Properties::Powered::FALSE:
                return 1092;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1093;
            case Properties::Powered::FALSE:
                return 1094;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1095;
            case Properties::Powered::FALSE:
                return 1096;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1097;
            case Properties::Powered::FALSE:
                return 1098;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1099;
            case Properties::Powered::FALSE:
                return 1100;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1101;
            case Properties::Powered::FALSE:
                return 1102;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1103;
            case Properties::Powered::FALSE:
                return 1104;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1105;
            case Properties::Powered::FALSE:
                return 1106;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1107;
            case Properties::Powered::FALSE:
                return 1108;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1109;
            case Properties::Powered::FALSE:
                return 1110;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1111;
            case Properties::Powered::FALSE:
                return 1112;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1113;
            case Properties::Powered::FALSE:
                return 1114;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1115;
            case Properties::Powered::FALSE:
                return 1116;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1117;
            case Properties::Powered::FALSE:
                return 1118;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1119;
            case Properties::Powered::FALSE:
                return 1120;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1121;
            case Properties::Powered::FALSE:
                return 1122;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1123;
            case Properties::Powered::FALSE:
                return 1124;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1125;
            case Properties::Powered::FALSE:
                return 1126;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1127;
            case Properties::Powered::FALSE:
                return 1128;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1129;
            case Properties::Powered::FALSE:
                return 1130;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1131;
            case Properties::Powered::FALSE:
                return 1132;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1133;
            case Properties::Powered::FALSE:
                return 1134;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1135;
            case Properties::Powered::FALSE:
                return 1136;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::BIT:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1137;
            case Properties::Powered::FALSE:
                return 1138;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1139;
            case Properties::Powered::FALSE:
                return 1140;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1141;
            case Properties::Powered::FALSE:
                return 1142;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1143;
            case Properties::Powered::FALSE:
                return 1144;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1145;
            case Properties::Powered::FALSE:
                return 1146;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1147;
            case Properties::Powered::FALSE:
                return 1148;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1149;
            case Properties::Powered::FALSE:
                return 1150;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1151;
            case Properties::Powered::FALSE:
                return 1152;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1153;
            case Properties::Powered::FALSE:
                return 1154;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1155;
            case Properties::Powered::FALSE:
                return 1156;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1157;
            case Properties::Powered::FALSE:
                return 1158;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1159;
            case Properties::Powered::FALSE:
                return 1160;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1161;
            case Properties::Powered::FALSE:
                return 1162;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1163;
            case Properties::Powered::FALSE:
                return 1164;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1165;
            case Properties::Powered::FALSE:
                return 1166;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1167;
            case Properties::Powered::FALSE:
                return 1168;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1169;
            case Properties::Powered::FALSE:
                return 1170;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1171;
            case Properties::Powered::FALSE:
                return 1172;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1173;
            case Properties::Powered::FALSE:
                return 1174;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1175;
            case Properties::Powered::FALSE:
                return 1176;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1177;
            case Properties::Powered::FALSE:
                return 1178;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1179;
            case Properties::Powered::FALSE:
                return 1180;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1181;
            case Properties::Powered::FALSE:
                return 1182;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1183;
            case Properties::Powered::FALSE:
                return 1184;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1185;
            case Properties::Powered::FALSE:
                return 1186;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::BANJO:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1187;
            case Properties::Powered::FALSE:
                return 1188;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1189;
            case Properties::Powered::FALSE:
                return 1190;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1191;
            case Properties::Powered::FALSE:
                return 1192;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1193;
            case Properties::Powered::FALSE:
                return 1194;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1195;
            case Properties::Powered::FALSE:
                return 1196;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1197;
            case Properties::Powered::FALSE:
                return 1198;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1199;
            case Properties::Powered::FALSE:
                return 1200;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1201;
            case Properties::Powered::FALSE:
                return 1202;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1203;
            case Properties::Powered::FALSE:
                return 1204;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1205;
            case Properties::Powered::FALSE:
                return 1206;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1207;
            case Properties::Powered::FALSE:
                return 1208;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1209;
            case Properties::Powered::FALSE:
                return 1210;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1211;
            case Properties::Powered::FALSE:
                return 1212;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1213;
            case Properties::Powered::FALSE:
                return 1214;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1215;
            case Properties::Powered::FALSE:
                return 1216;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1217;
            case Properties::Powered::FALSE:
                return 1218;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1219;
            case Properties::Powered::FALSE:
                return 1220;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1221;
            case Properties::Powered::FALSE:
                return 1222;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1223;
            case Properties::Powered::FALSE:
                return 1224;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1225;
            case Properties::Powered::FALSE:
                return 1226;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1227;
            case Properties::Powered::FALSE:
                return 1228;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1229;
            case Properties::Powered::FALSE:
                return 1230;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1231;
            case Properties::Powered::FALSE:
                return 1232;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1233;
            case Properties::Powered::FALSE:
                return 1234;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1235;
            case Properties::Powered::FALSE:
                return 1236;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::PLING:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1237;
            case Properties::Powered::FALSE:
                return 1238;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1239;
            case Properties::Powered::FALSE:
                return 1240;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1241;
            case Properties::Powered::FALSE:
                return 1242;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1243;
            case Properties::Powered::FALSE:
                return 1244;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1245;
            case Properties::Powered::FALSE:
                return 1246;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1247;
            case Properties::Powered::FALSE:
                return 1248;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1249;
            case Properties::Powered::FALSE:
                return 1250;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1251;
            case Properties::Powered::FALSE:
                return 1252;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1253;
            case Properties::Powered::FALSE:
                return 1254;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1255;
            case Properties::Powered::FALSE:
                return 1256;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1257;
            case Properties::Powered::FALSE:
                return 1258;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1259;
            case Properties::Powered::FALSE:
                return 1260;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1261;
            case Properties::Powered::FALSE:
                return 1262;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1263;
            case Properties::Powered::FALSE:
                return 1264;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1265;
            case Properties::Powered::FALSE:
                return 1266;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1267;
            case Properties::Powered::FALSE:
                return 1268;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1269;
            case Properties::Powered::FALSE:
                return 1270;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1271;
            case Properties::Powered::FALSE:
                return 1272;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1273;
            case Properties::Powered::FALSE:
                return 1274;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1275;
            case Properties::Powered::FALSE:
                return 1276;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1277;
            case Properties::Powered::FALSE:
                return 1278;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1279;
            case Properties::Powered::FALSE:
                return 1280;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1281;
            case Properties::Powered::FALSE:
                return 1282;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1283;
            case Properties::Powered::FALSE:
                return 1284;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1285;
            case Properties::Powered::FALSE:
                return 1286;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::ZOMBIE:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1287;
            case Properties::Powered::FALSE:
                return 1288;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1289;
            case Properties::Powered::FALSE:
                return 1290;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1291;
            case Properties::Powered::FALSE:
                return 1292;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1293;
            case Properties::Powered::FALSE:
                return 1294;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1295;
            case Properties::Powered::FALSE:
                return 1296;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1297;
            case Properties::Powered::FALSE:
                return 1298;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1299;
            case Properties::Powered::FALSE:
                return 1300;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1301;
            case Properties::Powered::FALSE:
                return 1302;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1303;
            case Properties::Powered::FALSE:
                return 1304;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1305;
            case Properties::Powered::FALSE:
                return 1306;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1307;
            case Properties::Powered::FALSE:
                return 1308;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1309;
            case Properties::Powered::FALSE:
                return 1310;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1311;
            case Properties::Powered::FALSE:
                return 1312;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1313;
            case Properties::Powered::FALSE:
                return 1314;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1315;
            case Properties::Powered::FALSE:
                return 1316;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1317;
            case Properties::Powered::FALSE:
                return 1318;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1319;
            case Properties::Powered::FALSE:
                return 1320;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1321;
            case Properties::Powered::FALSE:
                return 1322;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1323;
            case Properties::Powered::FALSE:
                return 1324;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1325;
            case Properties::Powered::FALSE:
                return 1326;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1327;
            case Properties::Powered::FALSE:
                return 1328;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1329;
            case Properties::Powered::FALSE:
                return 1330;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1331;
            case Properties::Powered::FALSE:
                return 1332;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1333;
            case Properties::Powered::FALSE:
                return 1334;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1335;
            case Properties::Powered::FALSE:
                return 1336;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::SKELETON:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1337;
            case Properties::Powered::FALSE:
                return 1338;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1339;
            case Properties::Powered::FALSE:
                return 1340;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1341;
            case Properties::Powered::FALSE:
                return 1342;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1343;
            case Properties::Powered::FALSE:
                return 1344;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1345;
            case Properties::Powered::FALSE:
                return 1346;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1347;
            case Properties::Powered::FALSE:
                return 1348;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1349;
            case Properties::Powered::FALSE:
                return 1350;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1351;
            case Properties::Powered::FALSE:
                return 1352;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1353;
            case Properties::Powered::FALSE:
                return 1354;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1355;
            case Properties::Powered::FALSE:
                return 1356;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1357;
            case Properties::Powered::FALSE:
                return 1358;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1359;
            case Properties::Powered::FALSE:
                return 1360;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1361;
            case Properties::Powered::FALSE:
                return 1362;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1363;
            case Properties::Powered::FALSE:
                return 1364;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1365;
            case Properties::Powered::FALSE:
                return 1366;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1367;
            case Properties::Powered::FALSE:
                return 1368;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1369;
            case Properties::Powered::FALSE:
                return 1370;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1371;
            case Properties::Powered::FALSE:
                return 1372;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1373;
            case Properties::Powered::FALSE:
                return 1374;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1375;
            case Properties::Powered::FALSE:
                return 1376;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1377;
            case Properties::Powered::FALSE:
                return 1378;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1379;
            case Properties::Powered::FALSE:
                return 1380;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1381;
            case Properties::Powered::FALSE:
                return 1382;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1383;
            case Properties::Powered::FALSE:
                return 1384;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1385;
            case Properties::Powered::FALSE:
                return 1386;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::CREEPER:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1387;
            case Properties::Powered::FALSE:
                return 1388;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1389;
            case Properties::Powered::FALSE:
                return 1390;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1391;
            case Properties::Powered::FALSE:
                return 1392;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1393;
            case Properties::Powered::FALSE:
                return 1394;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1395;
            case Properties::Powered::FALSE:
                return 1396;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1397;
            case Properties::Powered::FALSE:
                return 1398;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1399;
            case Properties::Powered::FALSE:
                return 1400;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1401;
            case Properties::Powered::FALSE:
                return 1402;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1403;
            case Properties::Powered::FALSE:
                return 1404;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1405;
            case Properties::Powered::FALSE:
                return 1406;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1407;
            case Properties::Powered::FALSE:
                return 1408;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1409;
            case Properties::Powered::FALSE:
                return 1410;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1411;
            case Properties::Powered::FALSE:
                return 1412;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1413;
            case Properties::Powered::FALSE:
                return 1414;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1415;
            case Properties::Powered::FALSE:
                return 1416;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1417;
            case Properties::Powered::FALSE:
                return 1418;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1419;
            case Properties::Powered::FALSE:
                return 1420;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1421;
            case Properties::Powered::FALSE:
                return 1422;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1423;
            case Properties::Powered::FALSE:
                return 1424;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1425;
            case Properties::Powered::FALSE:
                return 1426;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1427;
            case Properties::Powered::FALSE:
                return 1428;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1429;
            case Properties::Powered::FALSE:
                return 1430;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1431;
            case Properties::Powered::FALSE:
                return 1432;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1433;
            case Properties::Powered::FALSE:
                return 1434;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1435;
            case Properties::Powered::FALSE:
                return 1436;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::DRAGON:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1437;
            case Properties::Powered::FALSE:
                return 1438;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1439;
            case Properties::Powered::FALSE:
                return 1440;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1441;
            case Properties::Powered::FALSE:
                return 1442;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1443;
            case Properties::Powered::FALSE:
                return 1444;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1445;
            case Properties::Powered::FALSE:
                return 1446;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1447;
            case Properties::Powered::FALSE:
                return 1448;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1449;
            case Properties::Powered::FALSE:
                return 1450;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1451;
            case Properties::Powered::FALSE:
                return 1452;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1453;
            case Properties::Powered::FALSE:
                return 1454;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1455;
            case Properties::Powered::FALSE:
                return 1456;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1457;
            case Properties::Powered::FALSE:
                return 1458;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1459;
            case Properties::Powered::FALSE:
                return 1460;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1461;
            case Properties::Powered::FALSE:
                return 1462;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1463;
            case Properties::Powered::FALSE:
                return 1464;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1465;
            case Properties::Powered::FALSE:
                return 1466;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1467;
            case Properties::Powered::FALSE:
                return 1468;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1469;
            case Properties::Powered::FALSE:
                return 1470;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1471;
            case Properties::Powered::FALSE:
                return 1472;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1473;
            case Properties::Powered::FALSE:
                return 1474;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1475;
            case Properties::Powered::FALSE:
                return 1476;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1477;
            case Properties::Powered::FALSE:
                return 1478;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1479;
            case Properties::Powered::FALSE:
                return 1480;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1481;
            case Properties::Powered::FALSE:
                return 1482;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1483;
            case Properties::Powered::FALSE:
                return 1484;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1485;
            case Properties::Powered::FALSE:
                return 1486;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::WITHER_SKELETON:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1487;
            case Properties::Powered::FALSE:
                return 1488;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1489;
            case Properties::Powered::FALSE:
                return 1490;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1491;
            case Properties::Powered::FALSE:
                return 1492;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1493;
            case Properties::Powered::FALSE:
                return 1494;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1495;
            case Properties::Powered::FALSE:
                return 1496;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1497;
            case Properties::Powered::FALSE:
                return 1498;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1499;
            case Properties::Powered::FALSE:
                return 1500;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1501;
            case Properties::Powered::FALSE:
                return 1502;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1503;
            case Properties::Powered::FALSE:
                return 1504;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1505;
            case Properties::Powered::FALSE:
                return 1506;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1507;
            case Properties::Powered::FALSE:
                return 1508;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1509;
            case Properties::Powered::FALSE:
                return 1510;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1511;
            case Properties::Powered::FALSE:
                return 1512;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1513;
            case Properties::Powered::FALSE:
                return 1514;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1515;
            case Properties::Powered::FALSE:
                return 1516;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1517;
            case Properties::Powered::FALSE:
                return 1518;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1519;
            case Properties::Powered::FALSE:
                return 1520;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1521;
            case Properties::Powered::FALSE:
                return 1522;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1523;
            case Properties::Powered::FALSE:
                return 1524;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1525;
            case Properties::Powered::FALSE:
                return 1526;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1527;
            case Properties::Powered::FALSE:
                return 1528;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1529;
            case Properties::Powered::FALSE:
                return 1530;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1531;
            case Properties::Powered::FALSE:
                return 1532;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1533;
            case Properties::Powered::FALSE:
                return 1534;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1535;
            case Properties::Powered::FALSE:
                return 1536;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::PIGLIN:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1537;
            case Properties::Powered::FALSE:
                return 1538;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1539;
            case Properties::Powered::FALSE:
                return 1540;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1541;
            case Properties::Powered::FALSE:
                return 1542;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1543;
            case Properties::Powered::FALSE:
                return 1544;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1545;
            case Properties::Powered::FALSE:
                return 1546;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1547;
            case Properties::Powered::FALSE:
                return 1548;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1549;
            case Properties::Powered::FALSE:
                return 1550;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1551;
            case Properties::Powered::FALSE:
                return 1552;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1553;
            case Properties::Powered::FALSE:
                return 1554;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1555;
            case Properties::Powered::FALSE:
                return 1556;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1557;
            case Properties::Powered::FALSE:
                return 1558;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1559;
            case Properties::Powered::FALSE:
                return 1560;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1561;
            case Properties::Powered::FALSE:
                return 1562;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1563;
            case Properties::Powered::FALSE:
                return 1564;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1565;
            case Properties::Powered::FALSE:
                return 1566;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1567;
            case Properties::Powered::FALSE:
                return 1568;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1569;
            case Properties::Powered::FALSE:
                return 1570;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1571;
            case Properties::Powered::FALSE:
                return 1572;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1573;
            case Properties::Powered::FALSE:
                return 1574;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1575;
            case Properties::Powered::FALSE:
                return 1576;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1577;
            case Properties::Powered::FALSE:
                return 1578;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1579;
            case Properties::Powered::FALSE:
                return 1580;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1581;
            case Properties::Powered::FALSE:
                return 1582;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1583;
            case Properties::Powered::FALSE:
                return 1584;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1585;
            case Properties::Powered::FALSE:
                return 1586;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Instrument::CUSTOM_HEAD:
        switch (note) {
        case Properties::Note::ZERO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1587;
            case Properties::Powered::FALSE:
                return 1588;
            default:
                return 0;
            }
        case Properties::Note::ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1589;
            case Properties::Powered::FALSE:
                return 1590;
            default:
                return 0;
            }
        case Properties::Note::TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1591;
            case Properties::Powered::FALSE:
                return 1592;
            default:
                return 0;
            }
        case Properties::Note::THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1593;
            case Properties::Powered::FALSE:
                return 1594;
            default:
                return 0;
            }
        case Properties::Note::FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1595;
            case Properties::Powered::FALSE:
                return 1596;
            default:
                return 0;
            }
        case Properties::Note::FIVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1597;
            case Properties::Powered::FALSE:
                return 1598;
            default:
                return 0;
            }
        case Properties::Note::SIX:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1599;
            case Properties::Powered::FALSE:
                return 1600;
            default:
                return 0;
            }
        case Properties::Note::SEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1601;
            case Properties::Powered::FALSE:
                return 1602;
            default:
                return 0;
            }
        case Properties::Note::EIGHT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1603;
            case Properties::Powered::FALSE:
                return 1604;
            default:
                return 0;
            }
        case Properties::Note::NINE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1605;
            case Properties::Powered::FALSE:
                return 1606;
            default:
                return 0;
            }
        case Properties::Note::TEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1607;
            case Properties::Powered::FALSE:
                return 1608;
            default:
                return 0;
            }
        case Properties::Note::ELEVEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1609;
            case Properties::Powered::FALSE:
                return 1610;
            default:
                return 0;
            }
        case Properties::Note::TWELVE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1611;
            case Properties::Powered::FALSE:
                return 1612;
            default:
                return 0;
            }
        case Properties::Note::THIRTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1613;
            case Properties::Powered::FALSE:
                return 1614;
            default:
                return 0;
            }
        case Properties::Note::FOURTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1615;
            case Properties::Powered::FALSE:
                return 1616;
            default:
                return 0;
            }
        case Properties::Note::FIFTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1617;
            case Properties::Powered::FALSE:
                return 1618;
            default:
                return 0;
            }
        case Properties::Note::SIXTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1619;
            case Properties::Powered::FALSE:
                return 1620;
            default:
                return 0;
            }
        case Properties::Note::SEVENTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1621;
            case Properties::Powered::FALSE:
                return 1622;
            default:
                return 0;
            }
        case Properties::Note::EIGHTEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1623;
            case Properties::Powered::FALSE:
                return 1624;
            default:
                return 0;
            }
        case Properties::Note::NINETEEN:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1625;
            case Properties::Powered::FALSE:
                return 1626;
            default:
                return 0;
            }
        case Properties::Note::TWENTY:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1627;
            case Properties::Powered::FALSE:
                return 1628;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_ONE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1629;
            case Properties::Powered::FALSE:
                return 1630;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_TWO:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1631;
            case Properties::Powered::FALSE:
                return 1632;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_THREE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1633;
            case Properties::Powered::FALSE:
                return 1634;
            default:
                return 0;
            }
        case Properties::Note::TWENTY_FOUR:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 1635;
            case Properties::Powered::FALSE:
                return 1636;
            default:
                return 0;
            }
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
