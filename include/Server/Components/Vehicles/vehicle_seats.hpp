#pragma once

#include "vehicles.hpp"
#include <types.hpp>

namespace Impl
{

/// Returns 0xFF for invalid vehicles, and returns 0 for vehicles with only a driver.
inline uint8_t getVehiclePassengerSeats(int model)
{
	if (!isValidVehicleModel(model))
	{
		return 255;
	}

	static const StaticArray<uint8_t, MAX_VEHICLE_MODELS> allSeats = {
		10, // 400 - landstal
		10, // 401 - bravura
		10, // 402 - buffalo
		10, // 403 - linerun
		10, // 404 - peren
		10, // 405 - sentinel
		10, // 406 - dumper
		10, // 407 - firetruk
		10, // 408 - trash
		10, // 409 - stretch
		10, // 410 - manana
		10, // 411 - infernus
		10, // 412 - voodoo
		10, // 413 - pony
		10, // 414 - mule
		10, // 415 - cheetah
		10, // 416 - ambulan
		10, // 417 - leviathn
		10, // 418 - moonbeam
		10, // 419 - esperant
		10, // 420 - taxi
		10, // 421 - washing
		10, // 422 - bobcat
		10, // 423 - mrwhoop
		10, // 424 - bfinject
		10, // 425 - hunter
		10, // 426 - premier
		10, // 427 - enforcer
		10, // 428 - securica
		10, // 429 - banshee
		10, // 430 - predator
		10, // 431 - bus
		10, // 432 - rhino
		10, // 433 - barracks
		10, // 434 - hotknife
		10, // 435 - artict1
		10, // 436 - previon
		10, // 437 - coach
		10, // 438 - cabbie
		10, // 439 - stallion
		10, // 440 - rumpo
		10, // 441 - rcbandit
		10, // 442 - romero
		10, // 443 - packer
		10, // 444 - monster
		10, // 445 - admiral
		10, // 446 - squalo
		10, // 447 - seaspar
		10, // 448 - pizzaboy
		10, // 449 - tram
		10, // 450 - artict2
		10, // 451 - turismo
		10, // 452 - speeder
		10, // 453 - reefer
		10, // 454 - tropic
		10, // 455 - flatbed
		10, // 456 - yankee
		10, // 457 - caddy
		10, // 458 - solair
		10, // 459 - topfun
		10, // 460 - skimmer
		10, // 461 - pcj600
		10, // 462 - faggio
		10, // 463 - freeway
		10, // 464 - rcbaron
		10, // 465 - rcraider
		10, // 466 - glendale
		10, // 467 - oceanic
		10, // 468 - sanchez
		10, // 469 - sparrow
		10, // 470 - patriot
		10, // 471 - quad
		10, // 472 - coastg
		10, // 473 - dinghy
		10, // 474 - hermes
		10, // 475 - sabre
		10, // 476 - rustler
		10, // 477 - zr350
		10, // 478 - walton
		10, // 479 - regina
		10, // 480 - comet
		10, // 481 - bmx
		10, // 482 - burrito
		10, // 483 - camper
		10, // 484 - marquis
		10, // 485 - baggage
		10, // 486 - dozer
		10, // 487 - maverick
		10, // 488 - vcnmav
		10, // 489 - rancher
		10, // 490 - fbiranch
		10, // 491 - virgo
		10, // 492 - greenwoo
		10, // 493 - jetmax
		10, // 494 - hotring
		10, // 495 - sandking
		10, // 496 - blistac
		10, // 497 - polmav
		10, // 498 - boxville
		10, // 499 - benson
		10, // 500 - mesa
		10, // 501 - rcgoblin
		10, // 502 - hotrina
		10, // 503 - hotrinb
		10, // 504 - bloodra
		10, // 505 - rnchlure
		10, // 506 - supergt
		10, // 507 - elegant
		10, // 508 - journey
		10, // 509 - bike
		10, // 510 - mtbike
		10, // 511 - beagle
		10, // 512 - cropdust
		10, // 513 - stunt
		10, // 514 - petro
		10, // 515 - rdtrain
		10, // 516 - nebula
		10, // 517 - majestic
		10, // 518 - buccanee
		10, // 519 - shamal
		10, // 520 - hydra
		10, // 521 - fcr900
		10, // 522 - nrg500
		10, // 523 - copbike
		10, // 524 - cement
		10, // 525 - towtruck
		10, // 526 - fortune
		10, // 527 - cadrona
		10, // 528 - fbitruck
		10, // 529 - willard
		10, // 530 - forklift
		10, // 531 - tractor
		10, // 532 - combine
		10, // 533 - feltzer
		10, // 534 - remingtn
		10, // 535 - slamvan
		10, // 536 - blade
		10, // 537 - freight
		10, // 538 - streak
		10, // 539 - vortex
		10, // 540 - vincent
		10, // 541 - bullet
		10, // 542 - clover
		10, // 543 - sadler
		10, // 544 - firela
		10, // 545 - hustler
		10, // 546 - intruder
		10, // 547 - primo
		10, // 548 - cargobob
		10, // 549 - tampa
		10, // 550 - sunrise
		10, // 551 - merit
		10, // 552 - utility
		10, // 553 - nevada
		10, // 554 - yosemite
		10, // 555 - windsor
		10, // 556 - monstera
		10, // 557 - monsterb
		10, // 558 - uranus
		10, // 559 - jester
		10, // 560 - sultan
		10, // 561 - stratum
		10, // 562 - elegy
		10, // 563 - raindanc
		10, // 564 - rctiger
		10, // 565 - flash
		10, // 566 - tahoma
		10, // 567 - savanna
		10, // 568 - bandito
		10, // 569 - freiflat
		10, // 570 - streakc
		10, // 571 - kart
		10, // 572 - mower
		10, // 573 - duneride
		10, // 574 - sweeper
		10, // 575 - broadway
		10, // 576 - tornado
		10, // 577 - at400
		10, // 578 - dft30
		10, // 579 - huntley
		10, // 580 - stafford
		10, // 581 - bf400
		10, // 582 - newsvan
		10, // 583 - tug
		10, // 584 - petrotr
		10, // 585 - emperor
		10, // 586 - wayfarer
		10, // 587 - euros
		10, // 588 - hotdog
		10, // 589 - club
		10, // 590 - freibox
		10, // 591 - artict3
		10, // 592 - androm
		10, // 593 - dodo
		10, // 594 - rccam
		10, // 595 - launch
		10, // 596 - copcarla
		10, // 597 - copcarsf
		10, // 598 - copcarvg
		10, // 599 - copcarru
		10, // 600 - picador
		10, // 601 - swatvan
		10, // 602 - alpha
		10, // 603 - phoenix
		10, // 604 - glenshit
		10, // 605 - sadlshit
		10, // 606 - bagboxa
		10, // 607 - bagboxb
		10, // 608 - tugstair
		10, // 609 - boxburg
		10, // 610 - farmtr1
		10 // 611 - utiltr1
	};

	return allSeats[model - 400];
}

}
