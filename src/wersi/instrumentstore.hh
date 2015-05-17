// vim:set ts=4 sw=4 et cin:

/*
  DMS-Toolbox - an editor, librarian and converter for the Wersi DMS system
  (C) 2015 Michael Kukat <michael_AT_mik-music.org>

  This file is part of DMS-Toolbox.

  DMS-Toolbox is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  DMS-Toolbox is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with DMS-Toolbox.  If not, see <http://www.gnu.org/licenses/>.

  Diese Datei ist Teil von DMS-Toolbox.

  DMS-Toolbox ist Freie Software: Sie können es unter den Bedingungen
  der GNU General Public License, wie von der Free Software Foundation,
  Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
  veröffentlichten Version, weiterverbreiten und/oder modifizieren.

  DMS-Toolbox wird in der Hoffnung, dass es nützlich sein wird, aber
  OHNE JEDE GEWÄHELEISTUNG, bereitgestellt; sogar ohne die implizite
  Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
  Siehe die GNU General Public License für weitere Details.

  Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
  Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <common.hh>
#include <map>

namespace DMSToolbox {
namespace Wersi {

// Forward declarations
class Icb;
class Vcf;
class Envelope;
class Wave;

/**
  @ingroup wersi_group

  Wersi DMS-System instrument store.

  This is the general interface of an instrument store for the Wersi DMS-System.
 */
class InstrumentStore {
    public:
        /**
          Create new instrument store.

          Creates a new instrument store. If an explicit update() is called, the update() method of all contained
          objects is called to update their part of the buffer, then the store raw buffer is updated with this new
          information.
         */
        InstrumentStore();

        /**
          Destroy instrument store.

          Destroys the instrument store.
         */
        virtual ~InstrumentStore();

        /**
          Dissect instrument store raw data buffer.

          Parses the raw instrument store data buffer and updates object members.
         */
        virtual void dissect() = 0;

        /**
          Update instrument store raw data buffer.

          Writes back changes in the instrument store and children to the associated raw data buffer.
         */
        virtual void update() = 0;

        /**
          Get iterator to beginning of ICB map.

          Returns an iterator to the beginning of the ICB map.

          @return           Iterator to the beginning of the ICB map
         */
        std::map<uint8_t, Icb>::iterator begin();

        /**
          Get iterator to end of ICB map.

          Returns an iterator to the end of the ICB map.

          @return           Iterator to the end of the ICB map
         */
        std::map<uint8_t, Icb>::iterator end();

    protected:
        std::map<uint8_t, Icb>      m_icb;                  ///< ICB data
        std::map<uint8_t, Vcf>      m_vcf;                  ///< VCF data
        std::map<uint8_t, Envelope> m_ampl;                 ///< AMPL data
        std::map<uint8_t, Envelope> m_freq;                 ///< FREQ data
        std::map<uint8_t, Wave>     m_wave;                 ///< WAVE data

    private:
        InstrumentStore(const InstrumentStore&);            ///< Inhibit copying objects
        InstrumentStore& operator=(const InstrumentStore&); ///< Inhibit copying objects
};

} // namespace Wersi
} // namespace DMSToolbox
